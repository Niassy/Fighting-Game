#include "GameWorld.h"
#include "Lutteur.h"
#include "ressouces_file.h"
#include "Type_State.h"
#include "ui\UILoadingBar.h"

enum {
	kTagLabel1,
	kTagLabel2,
	kTagLabel3,
	kTagLabel4,
	kTagLabel5,
	kTagLabel6,
	kTagLabel7,
	kTagLabel8,
	kTagLoadingBar1,
	kTagLoadingBar2,
};



USING_NS_CC;
using namespace cocos2d::ui;

Scene* GameWorld::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = GameWorld::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool GameWorld::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	/////////////////////////////
	// 2. add a menu item with "X" image, which is clicked to quit the program
	//    you may modify it.

	// add a "close" icon to exit the progress. it's an autorelease object
	auto closeItem = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(GameWorld::menuCloseCallback, this));

	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width / 2,
		origin.y + closeItem->getContentSize().height / 2));

	// create menu, it's an autorelease object
	auto menu = Menu::create(closeItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);

	/////////////////////////////
	// 3. add your codes below...

	// add a label shows "Hello World"
	// create and initialize a label

	auto label = Label::createWithTTF("Door Daan", "fonts/Marker Felt.ttf", 24);

	// position the label on the center of the screen
	label->setPosition(Vec2(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height - label->getContentSize().height));

	// add the label as a child to this layer
	this->addChild(label, 1);

	// add "HelloWorld" splash screen"
	auto sprite = Sprite::create("BG.png");

	// position the sprite on the center of the screen
	sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	//sprite->setPosition(Vec2(0, 0));
	sprite->setScale(CC_CONTENT_SCALE_FACTOR() * 0.5);

	// add the sprite as a child to this layer
	this->addChild(sprite, 0);



	//


	// add the wrester

	Lutteur* lutteur = Lutteur::create();
	//lutteur->animateLewto();
	//lutteur->setPosition(Vec2(visibleSize.width / 2 + origin.x - 100, visibleSize.height / 2 + origin.y));
	lutteur->setPosition(Vec2(visibleSize.width / 2 + origin.x -  ( visibleSize.width / 4.8f), visibleSize.height / 2.2f + origin.y));

	m_pMainLutteur = lutteur;
	m_pMainLutteur->setOrientationLeft();
	m_pMainLutteur->Start();

	//

	Lutteur* lutteur1 = Lutteur::create();
	//lutteur1->animateLewtoDroite();
	//lutteur1->setPosition(Vec2(visibleSize.width / 2 + origin.x + 30, visibleSize.height / 2 + origin.y));
	lutteur1->setPosition(Vec2(visibleSize.width / 2 + origin.x + visibleSize.width / 16, visibleSize.height / 2.2f + origin.y));

	lutteur1->setOrientationRight();
	lutteur1->Start();
	lutteur1->setPosseded(true);
	//lutteur1->takePunch();
	//lutteur1->punch();

	this->addChild(lutteur,10);
	this->addChild(lutteur1,10);


	// set the world
	lutteur->m_pGame = this;
	lutteur1->m_pGame = this;


	m_pIALuttueur = lutteur1;



	////////////////////// Arbiter//////////////////

	m_bArbiterStart = false;
	addArbiter();

	///////////////////////////////////////////

	// other attributes
	m_fTimeRemainPunch = 0.5f;  // (for main player)
	m_bPunchPressed = false;

	m_fTimeSmash = 0.6f;

	m_bInputSmash = false;

	// ai
	m_fTimeRemainPunchIA = 0.0f;

	// Image Item
	auto item1 = MenuItemImage::create("Reculer BT.png", "Reculer BT.png", CC_CALLBACK_1(GameWorld::moveDownward, this));
	item1->setScale(CC_CONTENT_SCALE_FACTOR() * 0.15);
	//item1->setPositionX(item1->getPositionX() - 20 - 300);
	//item1->setPositionY(item1->getPositionY() + 10);


	m_MoveDownWardButton = item1;
	// for preventing changing position on other devices 

	item1->setPositionX(item1->getPositionX() -  visibleSize.width / 1.5f);
	item1->setPositionY(item1->getPositionY() + visibleSize.height / 32.0f);



	auto item2 = MenuItemImage::create("Avancer BT.png", "Avancer BT.png", CC_CALLBACK_1(GameWorld::moveForward, this));
	item2->setScale(CC_CONTENT_SCALE_FACTOR() * 0.15);
	//item2->setRotation(180);

	m_MoveForwardButton = item2;

	//item2->setPositionX(item2->getPositionX() + 60 - 300);
	//item2->setPositionY(item2->getPositionY() + 10);

	item2->setPositionX(item2->getPositionX()  - visibleSize.width /2.0f);
	item2->setPositionY(item2->getPositionY() + visibleSize.height / 32.0f);


	// punch button
	auto item3 = MenuItemImage::create("Sokh BT.png", "Sokh BT.png", CC_CALLBACK_1(GameWorld::punch, this));
	item3->setScale(CC_CONTENT_SCALE_FACTOR() * 0.15);
	//item3->setPositionY(item3->getPositionY() + 6);
	//item3->setPositionX(item3->getPositionX() - 20);

	m_PunchButton = item3;

	/*item3->setPositionX(item3->getPositionX() - visibleSize.width / 24);
	item3->setPositionY(item3->getPositionY() + visibleSize.height /53.33f );
*/

	item3->setPositionX(item3->getPositionX() - visibleSize.width / 24);
	item3->setPositionY(item3->getPositionY() + visibleSize.height / 4.84f);


	// upperut button
	//auto item4 = MenuItemImage::create("SokhBT.png", "SokhBT.png", CC_CALLBACK_1(GameWorld::uppercut, this));
	//item4->setScale(CC_CONTENT_SCALE_FACTOR() * 0.15);
	//item4->setPositionY(item4->getPositionY() + 66);
	//item4->setPositionX(item4->getPositionX() - 20);

	//item4->setPositionX(item4->getPositionX() - visibleSize.width / 24);
	//item4->setPositionY(item4->getPositionY() + visibleSize.height /4.84f );


	// daan button
	auto item5 = MenuItemImage::create("Daan BT.png", "Daan BT.png", "Daan BTR.png", CC_CALLBACK_1(GameWorld::daan, this));
	item5->setEnabled(false);
	//item5->setColor(Color3B::GRAY);

	// daan button
	m_DaanButton = item5;


	item5->setScale(CC_CONTENT_SCALE_FACTOR() * 0.15);

	//item5->setPositionX(item5->getPositionX() + 90);
	//item5->setPositionY(item5->getPositionY() + 46);

	item5->setPositionX(item5->getPositionX() + visibleSize.width /5.33f);
	item5->setPositionY(item5->getPositionY() +  visibleSize.height / 6.95f);

	//item5->setPositionY(item5->getPositionY() + visibleSize.height / 2);

	// feinte

	auto item6 = MenuItemImage::create("Feinte BT.png", "Feinte BT.PNG", CC_CALLBACK_1(GameWorld::block, this));
	item6->setScale(CC_CONTENT_SCALE_FACTOR() * 0.15);

	m_BlockButton = item6;
	//item6->setPositionX(item6->getPositionX() + 25);
	//item6->setPositionY(item6->getPositionY() + 46);

	item6->setPositionX(item6->getPositionX() + visibleSize.width /19.2f);
	item6->setPositionY(item6->getPositionY() + visibleSize.height / 6.95f);

	auto menu1 = Menu::create(item1, item2, item3, /*item4,*/ item5, item6, NULL);
	addChild(menu1);

	//menu1->setPosition(Vec2(visibleSize.width * 0.7, 20));

	menu1->setPosition(Vec2(visibleSize.width * 0.7, visibleSize.height / 16));

	//addLabelPower();
	//addLabelEnergy();


	// loading bar
	//addLoadingBar();

	// UI ADDING
	addIconWrestlerLeft();
	addIconWrestlerRight();
	addIconStaminaLeft();
	addIconStaminaRight();

	// the number of punch of ai
	m_iNumberPunch = 0;

	m_ElapsedTime = 0.0f;

	m_fTimeForStaring = 1.0f;

	m_bInputDaan = false;

	m_bMouseClick = false;

	m_bGameStarted = false;

	m_fTimeBeforeDance = 5.0f;


	// schedule update
	this->scheduleUpdate();

	//schedule(CC_SCHEDULE_SELECTOR(GameWorld::update), 5.0f);

	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(GameWorld::onTouchBegan, this);
	listener->onTouchEnded = CC_CALLBACK_2(GameWorld::onTouchEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);


	//lutteur->m_pGame->animateFXPunch(Vec2(30,30));

	//animateFXPunch(Vec2(200, 200));
	return true;
}


void GameWorld::menuCloseCallback(Ref* pSender)
{
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}

// this function move the wrestler forward(avancer)
void GameWorld::moveForward(cocos2d::Ref* pSender)
{

	if (m_pMainLutteur)
	{

		// exit when the wrestler is not on leweto
		if (!m_pMainLutteur->isInStateLeweto())
			return;


		// checking for collision
		if (/*m_pMainLutteur->getPosition().distance(m_pIALuttueur->getPosition()) >= 80*/!m_pMainLutteur->collide(m_pIALuttueur))
		{
			m_pMainLutteur->moveForward();
			//m_pMainLutteur->setPositionX(m_pMainLutteur->getPositionX() + 5);
		}
	}
}

// this function move the wrestler Downward(reculer)
void GameWorld::moveDownward(cocos2d::Ref* pSender)
{
	if (m_pMainLutteur)
	{
		if (!m_pMainLutteur->isInStateLeweto())
			return;

		if (!m_pMainLutteur->collideWithLeftScreen())
			//m_pMainLutteur->setPositionX(m_pMainLutteur->getPositionX() - 5);

			m_pMainLutteur->moveDownWard();
	}
}

// this function make the main  wrestler grab
void GameWorld::grab(cocos2d::Ref* pSender)
{
	if (m_pMainLutteur)
	{
		/*if (lutteur->m_fTimeBeforeSmash <= 0)
		{
		lutteur->m_iMaxSmash++;

		if (lutteur->m_bPosseded == false)
		{
		// you can use
		lutteur->m_iNumberSmash++;

		lutteur->m_fTimeBeforeSmash = 0.15f;

		}
		}*/
		m_pMainLutteur->grab();
	}
}

// this function makes the main wrestler 'daan'
void GameWorld::daan(cocos2d::Ref* pSender)
{
	if (!m_pMainLutteur)
		return;

	if (m_bInputDaan == true)
		return;

	if (m_pMainLutteur && !m_pMainLutteur->isInStateGrab())
	{
		m_bInputDaan = true;
		m_pMainLutteur->moveForward(Lutteur::getDistanceFromGrab());

	}

	if (m_pMainLutteur->isInStateGrab())
	{
		//m_bInputSmash = true;
		//m_pMainLutteur->setPositionX(m_pMainLutteur->getPositionX() + 10);
		m_pMainLutteur->m_iNumberSmash++;

	}

}

// this function make the main  wrestler smash
void GameWorld::smash(cocos2d::Ref* pSender)
{
	if (m_pMainLutteur)
	{
		m_pMainLutteur->m_iNumberSmash++;
	}
}

// this function make the main  wrestler punch
void GameWorld::punch(cocos2d::Ref* pSender)
{
	//if (m_bMouseClick)
		//return;

	/*if (m_pMainLutteur)
	m_pMainLutteur->animatePunch();*/

	if (m_pMainLutteur)
	{
		// exit when the wrestler is not on leweto
		if (!m_pMainLutteur->isInStateLeweto())
		{
			// make a punch toffo
			if (m_pMainLutteur->isInStateGrab())
			{
				m_pMainLutteur->punchRoffo();
				m_pIALuttueur->takePunchRoffo();
			}

			return;
		}

		if (!m_bPunchPressed)
		{
			m_bPunchPressed = true;

			if (m_pMainLutteur->getDistanceFromUppercut(m_pIALuttueur))
			{
				m_pMainLutteur->upperCut();
			}

			else
				m_pMainLutteur->punch();

		}

		// for debug
		//if (m_pIALuttueur)
		//m_pIALuttueur->takePunch();
	}

}

// this function makes the main wrestler 'daan'
void GameWorld::block(cocos2d::Ref* pSender)
{
	if (m_pMainLutteur)
	{
		if (!m_pMainLutteur->isInStateLeweto())
			return;

		m_pMainLutteur->block();

	}
}

// this function make the main  wrestler uppercut
void GameWorld::uppercut(cocos2d::Ref* pSender)
{

	//if (m_bMouseClick)
		//return;

	/*if (m_pMainLutteur)
	m_pMainLutteur->animateUppercut();*/


	if (m_pMainLutteur)
	{
		// exit when the wrestler is not on leweto
		//if (!m_pIALuttueur->isInStateLeweto())
			//return;

		if (!m_pMainLutteur->isInStateLeweto())
			return;

		m_pMainLutteur->upperCut();
	}
}



// update
// called once per frame
void GameWorld::update(float dt)
{
	
	/// timer
	m_ElapsedTime += dt;

	m_fTimeSmash -= dt;

	if (m_fTimeSmash <= 0)
		m_fTimeSmash = 0;

	if (m_pMainLutteur )
	{
		//m_pMainLutteur->setPositionX(m_pMainLutteur->getPositionX() + 1);

		if (m_ElapsedTime >= m_fTimeForStaring)
		{
			if (m_bGameStarted == false)
				m_bGameStarted = true;

			// test
			//if (!m_pMainLutteur->isInStateDefeat())
			m_pMainLutteur->update(dt, m_pIALuttueur);		
		}
	}


	// moved to updateAI function
	//if (m_pIALuttueur)
	//m_pIALuttueur->update(dt,m_pMainLutteur);


	if (m_ElapsedTime >= m_fTimeForStaring)
	{
		updateArbiter(dt);
		updateAI(dt);
	}


	// for activating daan button for smash

	
	// for activating daan button for daan
	if (m_pIALuttueur->isInStateEtourdi())
	{
		if (m_DaanButton)
		{
			if (!m_DaanButton->isEnabled())
			{
				m_DaanButton->setEnabled(true);

			}
		}

		// if the daan button is pushed
		// project the wrestler
		if ( m_pMainLutteur->getDistanceFromGrab(m_pIALuttueur)  /*&& hp2 < 10*/)
		{
			if (m_bInputDaan == true)
			{
				m_pMainLutteur->project();
				m_pIALuttueur->beProjected();
			}
		}
	}

	else
	{
		if (m_pIALuttueur->isInStateGrab())
		{
			if (m_DaanButton)
			{
				if (!m_DaanButton->isEnabled())
				{
					m_DaanButton->setEnabled(true);
				}
			}
		}

		else if (m_DaanButton)
		{
			if (m_DaanButton->isEnabled())
			{
				m_DaanButton->setEnabled(false);
				m_bInputDaan = false;


			}
		}
	}


	if (m_bPunchPressed == true)
	{
		m_fTimeRemainPunch -= dt;


		// avoiding a loop whe n push button is pressed
		if (m_fTimeRemainPunch <= 0)
		{
			m_fTimeRemainPunch = 0.5f;
			m_bPunchPressed = false;
		}

	}


	// energy update



	// time loading update
	//m_pMainLutteur->updateTimeReloadEnergy(dt);
	//m_pIALuttueur->updateTimeReloadEnergy(dt);


	//m_pIALuttueur->energie--;
	if (m_pIALuttueur->energie <0)
	{
		//m_pIALuttueur->energie = 100;
	}

	LoadingBar* loadingBar = static_cast<LoadingBar*>(getChildByTag(kTagLoadingBar1));

	LoadingBar* loadingBar2 = static_cast<LoadingBar*>(getChildByTag(kTagLoadingBar2));


	if (loadingBar)
	{

		// for the loading we have to make
		// an anlogy beetween values enery
		// of wrestler and loading bar values
		// for matching


		// 100 energie -> 85 loading bars
		//	val				X?
		// X = energie * 85 /100



		// 70 energie -> 100 loading bars
		//       val        X

		//  X  = 100  * energie / 70


		//loadingBar->setPercent( m_pIALuttueur->energie);


		//loadingBar->setPercent(( m_pIALuttueur->energie * 85 )  / 100);

		//loadingBar->setPercent(( m_pIALuttueur->energie * 100 )  / 70);



		if (CC_TARGET_PLATFORM != CC_PLATFORM_ANDROID)
			loadingBar->setPercent(m_pMainLutteur->loadingBarEnergy);






		// real analogy
		// suppose that the pucnh do 10 damage
		// the loading bar 85
		// we have seen that the loading is equal to 0 when it reaches 15
		// so the wrestler lose all loading bar when it is hit 10 times (10 *10)
		// on the loading bar context, 10  * 7

		// so the scale is 7/10

	}

	if (loadingBar2)
	{
		if (CC_TARGET_PLATFORM != CC_PLATFORM_ANDROID)
			loadingBar2->setPercent(m_pIALuttueur->loadingBarEnergy);

	}

	//updateLabelPower(dt);
	//updateLabelEnergy(dt);

	//m_bMouseClick = false;

	// input smash to false
	m_bInputSmash = false;


}

void GameWorld::updateAI(float dt)
{
	if (m_pIALuttueur )
	{
		//if (!m_pIALuttueur->isInStateDefeat())
		m_pIALuttueur->update(dt, m_pMainLutteur);

	}
}


// ai management
// this is core function of the game for managing ai
// 1st method
// use second method more clean
//void HelloWorld::updateAI(float dt)
//{
//	m_fTimeRemainPunchIA -= dt;
//
//	if (m_fTimeRemainPunchIA <= 0)
//		m_fTimeRemainPunchIA = 0;
//
//
//	// the ia
//	if (m_pIALuttueur)
//	{
//		// define the strategy
//
//		// state leweto
//		// what happens?
//		if (m_pIALuttueur->isInStateLeweto())
//		{
//			// only attack when near other wrestler
//			if (m_pIALuttueur->getPosition().distance(m_pMainLutteur->getPosition()) <= 100)
//			{
//				// testing for the grab
//
//				// cooldown timer for punching
//				// the ia enter on this state
//				if (m_fTimeRemainPunchIA <= 0)
//				{
//					if (m_iNumberPunch >=2)
//					{
//						m_iNumberPunch = 0;
//						m_pIALuttueur->grab();
//						if (m_pMainLutteur)
//							m_pMainLutteur->grab();
//
//					}
//
//					else
//					{
//						m_pIALuttueur->punch();
//						m_fTimeRemainPunchIA = 1.0f;
//						m_iNumberPunch++;
//
//					}
//					
//				}	
//			}
//
//			// the ai is not on leweto position
//			else
//			{
//				//else
//				//{
//					moveAIForward();
//				//}
//			}
//		}
//
//
//
//		// state grab
//		else if (m_pIALuttueur->isInStateGrab())
//		{
//			// test for the best smasher
//
//			//m_pIALuttueur->setPositionX(m_pIALuttueur->getPositionX() + 10);
//
//			// this was onlu for test
//			if (m_pIALuttueur->m_iNumberSmash >= 150)
//				m_pIALuttueur->project();
//
//
//			// to make the ia project() 
//			// we use this technique above
//			// when energy goes to 0
//
//			// the output of grab
//		}
//		m_pIALuttueur->update(dt, m_pMainLutteur);
//	}
//}


// move the ai
void GameWorld::moveAIForward()
{
	// exit when the wrestler is not on leweto
	if (!m_pIALuttueur->isInStateLeweto())
		return;


	// checking for collision
	if (m_pMainLutteur->getPosition().distance(m_pIALuttueur->getPosition()) >= 80)
	{
		m_pIALuttueur->moveForward();
		//m_pMainLutteur->setPositionX(m_pMainLutteur->getPositionX() + 5);
	}
}



// UI AND DESIGN


// add the portrait of the left wrestler
void GameWorld::addIconWrestlerLeft()
{
	// size
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();


	// add "HelloWorld" splash screen"
	auto sprite = Sprite::create("BayziarPIC.png");

	// position the sprite on the center of the screen
	sprite->setPosition(Vec2(visibleSize.width  *0.06 + origin.x, visibleSize.height *0.90 + origin.y));
	//sprite->setPosition(Vec2(0, 0));
	sprite->setScale(CC_CONTENT_SCALE_FACTOR() * 0.06);

	// add the sprite as a child to this layer
	this->addChild(sprite, 0);

}


// called for adding stamina
// for the right wrestler
void GameWorld::addIconWrestlerRight()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();


	// add "HelloWorld" splash screen"
	auto sprite = Sprite::create("MeukdoomPIC.png");

	// position the sprite on the center of the screen
	sprite->setPosition(Vec2(visibleSize.width  *0.95 + origin.x, visibleSize.height *0.90 + origin.y));
	//sprite->setPosition(Vec2(0, 0));
	sprite->setScale(CC_CONTENT_SCALE_FACTOR() * 0.06);

	// add the sprite as a child to this layer
	this->addChild(sprite, 0);


}


// called for adding stamina
// for the left wrestler
void GameWorld::addIconStaminaLeft()
{
	if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
		return;

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();


	// add "HelloWorld" splash screen"
	//auto sprite = Sprite::create("Stamina.png");

	// Create the loading bar
	LoadingBar* loadingBar = LoadingBar::create("Stamina.png");
	loadingBar->setTag(kTagLoadingBar1);
	loadingBar->setDirection(LoadingBar::Direction::RIGHT);


	// position the sprite on the center of the screen
	loadingBar->setPosition(Vec2(visibleSize.width  *0.28 + origin.x, visibleSize.height *0.95 + origin.y));
	//sprite->setPosition(Vec2(0, 0));
	loadingBar->setScale(CC_CONTENT_SCALE_FACTOR() * 0.2f);

	// add the sprite as a child to this layer
	this->addChild(loadingBar, 10);

	if (m_pMainLutteur)
		loadingBar->setPercent(m_pMainLutteur->loadingBarEnergy);

}


// add a stamina icon for the right wrestler
void GameWorld::addIconStaminaRight()
{
	if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
		return;

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();


	// Create the loading bar
	LoadingBar* loadingBar = LoadingBar::create("Stamina.png");
	loadingBar->setTag(kTagLoadingBar2);
	loadingBar->setDirection(LoadingBar::Direction::LEFT);


	// position the sprite on the center of the screen
	loadingBar->setPosition(Vec2(visibleSize.width  *0.72 + origin.x, visibleSize.height *0.95 + origin.y));
	//sprite->setPosition(Vec2(0, 0));
	loadingBar->setScale(CC_CONTENT_SCALE_FACTOR() * 0.2f);


	// add the sprite as a child to this layer
	this->addChild(loadingBar, 10);

	// slower th

	if (m_pIALuttueur)
		loadingBar->setPercent(m_pIALuttueur->loadingBarEnergy);

}


// add label for power
void GameWorld::addLabelPower()
{
	auto s = Director::getInstance()->getWinSize();

	auto label1 = Label::createWithTTF("Power :", "fonts/Marker Felt.ttf", 24);


	//label1->setString("power");
	//label1->setFontName("Arial");

	addChild(label1, 10, kTagLabel1);
	label1->setPosition(Vec2(s.width *0.2, (s.height / 6) * 5));
	label1->setColor(Color3B::GREEN);
	//label1->setPosition(Vec2(400, 400));

}


// update the label for power
void GameWorld::updateLabelPower(float dt)
{
	auto label1 = (LabelTTF*)getChildByTag(kTagLabel1);
	char string[12] = { 0 };

	sprintf(string, "Power :%d", (int)m_pIALuttueur->getPower());
	//string.format("%d", (int)_time);
	label1->setString(string);
}


// add label for damage 
void GameWorld::addLabelDamage()
{

}


// update the label for damage
void GameWorld::updateLabelDamage(float dt)
{

}


// add label for energy display
void GameWorld::addLabelEnergy()
{
	auto s = Director::getInstance()->getWinSize();
	auto label1 = Label::createWithTTF("Energy :", "fonts/Marker Felt.ttf", 24);


	//label1->setString("power");
	//label1->setFontName("Arial");

	addChild(label1, 10, kTagLabel2);
	label1->setPosition(Vec2(s.width *0.2, (s.height / 6) * 4));
	label1->setColor(Color3B::GREEN);

}


// update the label
void GameWorld::updateLabelEnergy(float dt)
{

	auto label1 = (LabelTTF*)getChildByTag(kTagLabel2);
	char string[12] = { 0 };

	sprintf(string, "Energy :%d", (int)m_pIALuttueur->getEnergy());
	//string.format("%d", (int)_time);
	label1->setString(string);
}



// loading bar
void GameWorld::addLoadingBar()
{
	if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
		return;

	// size
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();


	// Create the loading bar
	LoadingBar* loadingBar = LoadingBar::create("sliderProgress.png");
	loadingBar->setTag(kTagLoadingBar1);
	loadingBar->setPosition(Vec2(visibleSize.width  *0.28 + origin.x, visibleSize.height *0.95 + origin.y));
	loadingBar->setDirection(LoadingBar::Direction::RIGHT);
	addChild(loadingBar, 12);
	loadingBar->setScale(CC_CONTENT_SCALE_FACTOR() * 0.55);
	loadingBar->setScaleX(CC_CONTENT_SCALE_FACTOR() * 0.33);

	if (m_pIALuttueur)
		loadingBar->setPercent((m_pIALuttueur->energie * 85) / 100);

}


// the width of the screen
float GameWorld::getWidth()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();

	return visibleSize.width;
}

// the heiht of the screen
float GameWorld::getHeight()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	return visibleSize.height;
}



bool GameWorld::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event)
{
	return true ;
}

void GameWorld::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event)
{
	desactivateAllButtons();

	m_bMouseClick = true;
}


void GameWorld::ActivateAllButtons()
{
	if (m_MoveDownWardButton)
		m_MoveDownWardButton->setEnabled(false);

	if (m_MoveForwardButton)
		m_MoveForwardButton->setEnabled(false);

	if (m_PunchButton)
		m_PunchButton->setEnabled(false);

	if (m_BlockButton)
		m_BlockButton->setEnabled(false);
}
void GameWorld::desactivateAllButtons()
{

	if (m_MoveDownWardButton)
		m_MoveDownWardButton->setEnabled(true);

	if (m_MoveForwardButton)
		m_MoveForwardButton->setEnabled(true);

	if (m_PunchButton)
		m_PunchButton->setEnabled(true);

	if (m_BlockButton)
		m_BlockButton->setEnabled(true);
}



///////////////// fx animation ///////////////


void GameWorld::animateFXPunch(Vec2 pos)
{
	auto fx = Sprite::create();

	auto animation = Animation::create();
	for (int i = 0; i<6; i++)
	{
		char szName[100] = { 0 };
		sprintf(szName, "FX/PUNCH/Energy 07/1_%05d.png", i);
		animation->addSpriteFrameWithFile(szName);
	}
	// should last 2.8 seconds. And there are 14 frames.
	animation->setDelayPerUnit(0.8f / 6.0f);
	animation->setRestoreOriginalFrame(true);

	auto action = Animate::create(animation);
	fx->setPosition(pos);
	fx->setScale(CC_CONTENT_SCALE_FACTOR() * 0.1f);
	fx->runAction(Sequence::create(action, RemoveSelf::create(), nullptr));

	addChild(fx, 10);


}

void GameWorld::animateFXUppercutGauche(Vec2 pos)
{
	auto fx = Sprite::create();

	auto animation = Animation::create();
	for (int i = 0; i<11; i++)
	{
		char szName[100] = { 0 };
		sprintf(szName, "FX/UPPERCUT/GAUCHE/Energy 13/1_%05d.png", i);
		animation->addSpriteFrameWithFile(szName);
	}


	// should last 2.8 seconds. And there are 14 frames.
	animation->setDelayPerUnit(1.0f / 11.0f);
	animation->setRestoreOriginalFrame(true);

	auto action = Animate::create(animation);
	fx->setPosition(pos);
	fx->setScale(CC_CONTENT_SCALE_FACTOR() * 0.1f);

	fx->runAction(Sequence::create(action, RemoveSelf::create(), nullptr));

	addChild(fx, 10);

}
void GameWorld::animateFXUppercutDroite(Vec2 pos)
{

	auto fx = Sprite::create();

	auto animation = Animation::create();
	for (int i = 0; i<11; i++)
	{
		char szName[100] = { 0 };
		sprintf(szName, "FX/UPPERCUT/DROITE/Energy 13/1_%05d.png", i);
		animation->addSpriteFrameWithFile(szName);
	}


	// should last 2.8 seconds. And there are 14 frames.
	animation->setDelayPerUnit(1.0f / 11.0f);
	animation->setRestoreOriginalFrame(true);

	auto action = Animate::create(animation);
	fx->setPosition(pos);
	fx->setScale(CC_CONTENT_SCALE_FACTOR() * 0.1f);
	fx->runAction(Sequence::create(action, RemoveSelf::create(), nullptr));

	addChild(fx, 10);

}

void GameWorld::animateFXEtourdi(Vec2 pos)
{
	auto fx = Sprite::create();
	auto animation = Animation::create();
	for (int i = 0; i<15; i++)
	{
		char szName[100] = { 0 };
		sprintf(szName, "FX/ETOURDI/Energy 01/1_%05d.png", i);
		animation->addSpriteFrameWithFile(szName);
	}

	// should last 2.8 seconds. And there are 14 frames.
	animation->setDelayPerUnit(0.9f / 14.0f);
	animation->setRestoreOriginalFrame(true);

	auto action = Animate::create(animation);
	fx->setPosition(pos);
	fx->setScale(CC_CONTENT_SCALE_FACTOR() * 0.1f);
	fx->runAction(Sequence::create(action, RemoveSelf::create(), nullptr));

	addChild(fx, 10);
}



void GameWorld::animateFXWalk(Vec2 pos)
{
	auto fx = Sprite::create();
	auto animation = Animation::create();
	for (int i = 0; i<25; i++)
	{
		char szName[100] = { 0 };
		sprintf(szName, "FX/WALK/Smoke Explosion 16/1_%05d.png", i);
		animation->addSpriteFrameWithFile(szName);
	}

	// should last 2.8 seconds. And there are 14 frames.
	animation->setDelayPerUnit(0.9f / 25.0f);
	animation->setRestoreOriginalFrame(true);

	auto action = Animate::create(animation);
	fx->setPosition(pos);
	fx->setScale(CC_CONTENT_SCALE_FACTOR() * 0.1f);
	fx->runAction(Sequence::create(action, RemoveSelf::create(), nullptr));

	addChild(fx, 10);

}



////////////////////////////// Arbiter///////////////////////////

void GameWorld::addArbiter()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();


	auto arbiter = Sprite::create("ARBITRE/LANCER_COMBAT/Image.001.png");
	arbiter->setPosition(Vec2(visibleSize.width / 2.5f + origin.x , visibleSize.height / 2.2f + origin.y));
	arbiter->setScale(CC_CONTENT_SCALE_FACTOR() * 0.18);


	addChild(arbiter,2);
	m_pAribiter = arbiter;

	//auto animation = Animation::create();
	//for (int i = 1; i<3; i++)
	//{
	//	char szName[100] = { 0 };
	//	sprintf(szName, "FX/1_%03d.png", i);
	//	animation->addSpriteFrameWithFile(szName);
	//}

	//// should last 2.8 seconds. And there are 14 frames.
	//animation->setDelayPerUnit(0.9f / 25.0f);
	//animation->setRestoreOriginalFrame(true);

	//auto action = Animate::create(animation);
	//fx->setPosition(pos);
	//fx->setScale(CC_CONTENT_SCALE_FACTOR() * 0.1f);
	//fx->runAction(Sequence::create(action, RemoveSelf::create(), nullptr));



}

void GameWorld::updateArbiter(float dt)
{
	if (m_pAribiter)
	{


		 // finish the game
		//if (m_pMainLutteur)
		//{
		//	if (m_pMainLutteur->isInStateDefeat())
		//	{
		//		auto animation = Animation::create();
		//		for (int i = 1; i < 3; i++)
		//		{
		//			char szName[100] = { 0 };
		//			sprintf(szName, "ARBITRE/TERMINER_COMBAT/image.%03d.png", i);
		//			animation->addSpriteFrameWithFile(szName);
		//		}

		//		// should last 2.8 seconds. And there are 14 frames.
		//		animation->setDelayPerUnit(2.2f / 2.0f);
		//		animation->setRestoreOriginalFrame(false);

		//		auto action = Animate::create(animation);
		//		//m_pAribiter->setScale(CC_CONTENT_SCALE_FACTOR() * 0.1f);
		//		//m_pAribiter->runAction(Sequence::create(action, RemoveSelf::create(), nullptr));
		//		m_pAribiter->runAction(action);
		//		return;

		//	}
		//}

		//if (m_pIALuttueur)
		//{
		//	if (m_pIALuttueur->isInStateDefeat())
		//	{
		//		auto animation = Animation::create();
		//		for (int i = 1; i < 3; i++)
		//		{
		//			char szName[100] = { 0 };
		//			sprintf(szName, "ARBITRE/TERMINER_COMBAT/image.%03d.png", i);
		//			animation->addSpriteFrameWithFile(szName);
		//		}

		//		// should last 2.8 seconds. And there are 14 frames.
		//		animation->setDelayPerUnit(2.0f / 2.0f);
		//		animation->setRestoreOriginalFrame(false);

		//		auto action = Animate::create(animation);
		//		//m_pAribiter->setScale(CC_CONTENT_SCALE_FACTOR() * 0.1f);
		//		//m_pAribiter->runAction(Sequence::create(action, RemoveSelf::create(), nullptr));
		//		m_pAribiter->runAction(action);
		//		return;

		//	}
		//}

		// start the game
		if (m_bArbiterStart == false)
		{
			auto animation = Animation::create();
			for (int i = 1; i < 3; i++)
			{
				char szName[100] = { 0 };
				sprintf(szName, "ARBITRE/LANCER_COMBAT/image.%03d.png", i);
				animation->addSpriteFrameWithFile(szName);
			}

			// should last 2.8 seconds. And there are 14 frames.
			animation->setDelayPerUnit(0.8f / 2.0f);
			animation->setRestoreOriginalFrame(false);

			auto action = Animate::create(animation);
			//m_pAribiter->setScale(CC_CONTENT_SCALE_FACTOR() * 0.1f);
			//m_pAribiter->runAction(Sequence::create(action, RemoveSelf::create(), nullptr));
			//m_pAribiter->runAction(action);

			m_pAribiter->runAction(Sequence::create(
				action,
				CallFunc::create(CC_CALLBACK_0(GameWorld::arbiterFollow, this)),
				nullptr)
				);

			m_bArbiterStart = true;
		}

		else
		{
			//m_fTimeForStaring -= dt;

			//if (m_fTimeForStaring <= 0)
			//	m_pAribiter->setTexture("ARBITRE/SUIVRE_COMBAT/image.001.png");
		}


		// follow the match

	}

}


void GameWorld:: arbiterFollow()
{
   m_pAribiter->setTexture("ARBITRE/SUIVRE_COMBAT/image.001.png");
}

void GameWorld::arbiterFinish()
{
	auto animation = Animation::create();
	for (int i = 1; i < 3; i++)
	{
		char szName[100] = { 0 };
		sprintf(szName, "ARBITRE/TERMINER_COMBAT/image.%03d.png", i);
		animation->addSpriteFrameWithFile(szName);
	}

	// should last 2.8 seconds. And there are 14 frames.
	animation->setDelayPerUnit(2.2f / 2.0f);
	animation->setRestoreOriginalFrame(false);

	auto action = Animate::create(animation);
	//m_pAribiter->setScale(CC_CONTENT_SCALE_FACTOR() * 0.1f);
	//m_pAribiter->runAction(Sequence::create(action, RemoveSelf::create(), nullptr));
	m_pAribiter->runAction(action);
			
}

//////////////////////////////////////////////////////////
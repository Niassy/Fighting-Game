//#include "HelloWorldScene.h"
//#include "Lutteur.h"
//#include "ressouces_file.h"
//#include "Type_State.h"
//#include "ui\UILoadingBar.h"
//
//enum {
//	kTagLabel1,
//	kTagLabel2,
//	kTagLabel3,
//	kTagLabel4,
//	kTagLabel5,
//	kTagLabel6,
//	kTagLabel7,
//	kTagLabel8,
//	kTagLoadingBar1,
//	kTagLoadingBar2,
//};
//
//
//
//USING_NS_CC;
//using namespace cocos2d::ui;
//
//Scene* HelloWorld::createScene()
//{
//    // 'scene' is an autorelease object
//    auto scene = Scene::create();
//    
//    // 'layer' is an autorelease object
//    auto layer = HelloWorld::create();
//
//    // add layer as a child to scene
//    scene->addChild(layer);
//
//    // return the scene
//    return scene;
//}
//
//// on "init" you need to initialize your instance
//bool HelloWorld::init()
//{
//    //////////////////////////////
//    // 1. super init first
//    if ( !Layer::init() )
//    {
//        return false;
//    }
//    
//    Size visibleSize = Director::getInstance()->getVisibleSize();
//    Vec2 origin = Director::getInstance()->getVisibleOrigin();
//
//    /////////////////////////////
//    // 2. add a menu item with "X" image, which is clicked to quit the program
//    //    you may modify it.
//
//    // add a "close" icon to exit the progress. it's an autorelease object
//    auto closeItem = MenuItemImage::create(
//                                           "CloseNormal.png",
//                                           "CloseSelected.png",
//                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
//    
//	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
//                                origin.y + closeItem->getContentSize().height/2));
//
//    // create menu, it's an autorelease object
//    auto menu = Menu::create(closeItem, NULL);
//    menu->setPosition(Vec2::ZERO);
//    this->addChild(menu, 1);
//
//    /////////////////////////////
//    // 3. add your codes below...
//
//    // add a label shows "Hello World"
//    // create and initialize a label
//    
//    auto label = Label::createWithTTF("Door Daan", "fonts/Marker Felt.ttf", 24);
//    
//    // position the label on the center of the screen
//    label->setPosition(Vec2(origin.x + visibleSize.width/2,
//                            origin.y + visibleSize.height - label->getContentSize().height));
//
//    // add the label as a child to this layer
//    this->addChild(label, 1);
//
//    // add "HelloWorld" splash screen"
//    auto sprite = Sprite::create("BG.png");
//
//    // position the sprite on the center of the screen
//    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
//	//sprite->setPosition(Vec2(0, 0));
//	sprite->setScale(0.5);
//
//    // add the sprite as a child to this layer
//    this->addChild(sprite, 0);
//    
//
//	
//	//
//
//
//	// add the wrester
//
//	Lutteur* lutteur = Lutteur::create();
//	//lutteur->animateLewto();
//	lutteur->setPosition(Vec2(visibleSize.width / 2 + origin.x - 100 , visibleSize.height / 2 + origin.y));
//	m_pMainLutteur = lutteur;
//	m_pMainLutteur->setOrientationLeft();
//	m_pMainLutteur->Start();
//
//	//
//
//	Lutteur* lutteur1 = Lutteur::create();
//	//lutteur1->animateLewtoDroite();
//	lutteur1->setPosition(Vec2(visibleSize.width / 2 + origin.x  + 30, visibleSize.height / 2 + origin.y));
//	lutteur1->setOrientationRight();
//	lutteur1->Start();
//	lutteur1->setPosseded(true);
//	//lutteur1->takePunch();
//	//lutteur1->punch();
//
//	this->addChild(lutteur);
//	this->addChild(lutteur1);
//
//
//	// set the world
//	lutteur->m_pGame = this;
//	lutteur1->m_pGame = this;
//
//
//	m_pIALuttueur = lutteur1;
//
//	// other attributes
//	m_fTimeRemainPunch = 0.5f;  // (for main player)
//	m_bPunchPressed = false;
//
//	m_fTimeSmash = 0.6f;
//
//	m_bInputSmash = false;
//
//	// ai
//	m_fTimeRemainPunchIA = 0.0f;
//
//	// Image Item
//	auto item1 = MenuItemImage::create("ReculerBT.png", "ReculerBT.png", CC_CALLBACK_1(HelloWorld::moveDownward, this));
//	item1->setScale(0.15);
//	item1->setPositionX(item1->getPositionX() - 20 -300);
//	item1->setPositionY(item1->getPositionY() + 10);
//
//
//	auto item2 = MenuItemImage::create("AvancerBT.png", "AvancerBT.png", CC_CALLBACK_1(HelloWorld::moveForward, this));
//	item2->setScale(0.15);
//	//item2->setRotation(180);
//	item2->setPositionX(item2->getPositionX() + 60 - 300);
//	item2->setPositionY(item2->getPositionY() + 10);
//
//
//	// punch button
//	auto item3 = MenuItemImage::create("SokhBT.png", "SokhBT.png", CC_CALLBACK_1(HelloWorld::punch, this));
//	item3->setScale(0.15);
//	item3->setPositionY(item3->getPositionY() + 6);
//	item3->setPositionX(item3->getPositionX() -20);
//
//
//	// upperut button
//	auto item4 = MenuItemImage::create("SokhBT.png", "SokhBT.png", CC_CALLBACK_1(HelloWorld::uppercut, this));
//	item4->setScale(0.15);
//	item4->setPositionY(item4->getPositionY() + 66);
//	item4->setPositionX(item4->getPositionX() -20);
//
//
//
//	// daan button
//	auto item5 = MenuItemImage::create("DaanBT.png", "DaanBT.png", CC_CALLBACK_1(HelloWorld::uppercut, this));
//	item5->setScale(0.15);
//	item5->setPositionX(item5->getPositionX() + 90);
//
//	item5->setPositionY(item5->getPositionY() + 46);
//	
//
//	// feinte
//	
//	auto item6 = MenuItemImage::create("FeinteBT.png", "FeinteBT.PNG", CC_CALLBACK_1(HelloWorld::uppercut, this));
//	item6->setScale(0.15);
//	item6->setPositionX(item6->getPositionX() + 25);
//	item6->setPositionY(item6->getPositionY() + 46);
//	
//
//	auto menu1 = Menu::create(item1, item2, item3,item4,item5,item6, NULL);
//	addChild(menu1);
//	menu1->setPosition(Vec2(visibleSize.width * 0.7, 20));
//
//
//	//addLabelPower();
//	//addLabelEnergy();
//
//
//	// loading bar
//	//addLoadingBar();
//
//
//	// UI ADDING
//	addIconWrestlerLeft();
//	addIconWrestlerRight();
//	addIconStaminaLeft();
//	addIconStaminaRight();
//
//
//	// the number of punch of ai
//	m_iNumberPunch = 0;
//
//	m_ElapsedTime = 0.0f;
//
//	// schedule update
//	this->scheduleUpdate();
//
//    return true;
//}
//
//
//void HelloWorld::menuCloseCallback(Ref* pSender)
//{
//    Director::getInstance()->end();
//
//#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
//    exit(0);
//#endif
//}
//
//// this function move the wrestler forward(avancer)
//void HelloWorld::moveForward(cocos2d::Ref* pSender)
//{
//
//	if (m_pMainLutteur)
//	{
//
//		// exit when the wrestler is not on leweto
//		if (!m_pMainLutteur->isInStateLeweto())
//			return;
//
//
//		// checking for collision
//		if (/*m_pMainLutteur->getPosition().distance(m_pIALuttueur->getPosition()) >= 80*/!m_pMainLutteur->collide(m_pIALuttueur))
//		{
//			m_pMainLutteur->moveForward();
//			//m_pMainLutteur->setPositionX(m_pMainLutteur->getPositionX() + 5);
//		}
//	}
//}
//
//// this function move the wrestler Downward(reculer)
//void HelloWorld::moveDownward(cocos2d::Ref* pSender)
//{
//	if (m_pMainLutteur)
//	{
//		if (!m_pMainLutteur->isInStateLeweto())
//			return;
//
//		if (!m_pMainLutteur->collideWithLeftScreen())
//		//m_pMainLutteur->setPositionX(m_pMainLutteur->getPositionX() - 5);
//
//			m_pMainLutteur->moveDownWard();
//	}
//}
//
//// this function make the main  wrestler grab
//void HelloWorld::grab(cocos2d::Ref* pSender)
//{
//	if (m_pMainLutteur)
//	{
//		/*if (lutteur->m_fTimeBeforeSmash <= 0)
//		{
//			lutteur->m_iMaxSmash++;
//
//			if (lutteur->m_bPosseded == false)
//			{
//				// you can use 
//				lutteur->m_iNumberSmash++;
//
//				lutteur->m_fTimeBeforeSmash = 0.15f;
//
//			}
//		}*/
//		m_pMainLutteur->grab();
//	}
//}
//
//// this function make the main  wrestler smash
//void HelloWorld::smash(cocos2d::Ref* pSender)
//{
//	if (m_pMainLutteur)
//	{
//		m_pMainLutteur->m_iNumberSmash++;
//	}
//}
//
//// this function make the main  wrestler punch
//void HelloWorld::punch(cocos2d::Ref* pSender)
//{
//	/*if (m_pMainLutteur)
//		m_pMainLutteur->animatePunch();*/
//
//	if (m_pMainLutteur)
//	{
//
//		// exit when the wrestler is not on leweto
//		if (!m_pMainLutteur->isInStateLeweto())
//			return;
//
//		if (!m_bPunchPressed)
//		{
//
//			m_pMainLutteur->punch();
//			m_bPunchPressed = true;
//		}
//		// for debug
//		//if (m_pIALuttueur)
//			//m_pIALuttueur->takePunch();
//	}
//
//}
//
//// this function make the main  wrestler uppercut
//void HelloWorld::uppercut(cocos2d::Ref* pSender)
//{
//	/*if (m_pMainLutteur)
//		m_pMainLutteur->animateUppercut();*/
//
//	if (m_pMainLutteur)
//	{
//		// exit when the wrestler is not on leweto
//		if (!m_pIALuttueur->isInStateLeweto())
//			return;
//
//
//		m_pMainLutteur->upperCut();
//	}
//}
//
//
//
//// update
//// called once per frame
//void HelloWorld::update(float dt)
//{
//
//	/// timer
//	m_ElapsedTime += dt;
//
//	m_fTimeSmash -= dt;
//
//	if (m_fTimeSmash <= 0)
//		m_fTimeSmash = 0;
//
//	if (m_pMainLutteur)
//	{
//		//m_pMainLutteur->setPositionX(m_pMainLutteur->getPositionX() + 1);
//		m_pMainLutteur->update(dt,m_pIALuttueur);
//	}
//
//
//	// moved to updateAI function
//	//if (m_pIALuttueur)
//		//m_pIALuttueur->update(dt,m_pMainLutteur);
//
//
//	updateAI(dt);
//
//	if (m_bPunchPressed == true)
//	{
//		m_fTimeRemainPunch -= dt;
//
//
//		// avoiding a loop whe n push button is pressed
//		if (m_fTimeRemainPunch <= 0)
//		{
//			m_fTimeRemainPunch = 0.5f;
//			m_bPunchPressed = false;
//		}
//
//	}
//
//	
//
//	// energy update
//
//
//
//	// time loading update
//	m_pMainLutteur->updateTimeReloadEnergy(dt);
//	m_pIALuttueur->updateTimeReloadEnergy(dt);
//
//
//	//m_pIALuttueur->energie--;
//	if (m_pIALuttueur->energie <0)
//	{
//		//m_pIALuttueur->energie = 100;
//	}
//
//	LoadingBar* loadingBar = static_cast<LoadingBar*>(getChildByTag(kTagLoadingBar1));
//
//	LoadingBar* loadingBar2 = static_cast<LoadingBar*>(getChildByTag(kTagLoadingBar2));
//
//
//	if (loadingBar)
//	{
//
//		// for the loading we have to make
//		// an anlogy beetween values enery
//		// of wrestler and loading bar values
//		// for matching
//
//
//		// 100 energie -> 85 loading bars
//		//	val				X?
//		// X = energie * 85 /100
//
//
//
//		// 70 energie -> 100 loading bars
//		//       val        X
//
//		//  X  = 100  * energie / 70
//
//
//		//loadingBar->setPercent( m_pIALuttueur->energie);
//
//
//		//loadingBar->setPercent(( m_pIALuttueur->energie * 85 )  / 100);
//
//		//loadingBar->setPercent(( m_pIALuttueur->energie * 100 )  / 70);
//
//
//		loadingBar->setPercent(m_pMainLutteur->loadingBarEnergy);
//
//
//		
//
//
//
//		// real analogy
//		// suppose that the pucnh do 10 damage
//		// the loading bar 85
//		// we have seen that the loading is equal to 0 when it reaches 15
//		// so the wrestler lose all loading bar when it is hit 10 times (10 *10)
//		// on the loading bar context, 10  * 7
//
//		// so the scale is 7/10
//
//	}
//
//	if (loadingBar2)
//	{
//		loadingBar2->setPercent(m_pIALuttueur->loadingBarEnergy);
//
//	}
//
//	//updateLabelPower(dt);
//	//updateLabelEnergy(dt);
//
//}
//
//void HelloWorld::updateAI(float dt)
//{
//	if (m_pIALuttueur)
//	{
//		m_pIALuttueur->update(dt, m_pMainLutteur);
//
//	}
//}
//
//
//// ai management
//// this is core function of the game for managing ai
//// 1st method
//// use second method more clean
////void HelloWorld::updateAI(float dt)
////{
////	m_fTimeRemainPunchIA -= dt;
////
////	if (m_fTimeRemainPunchIA <= 0)
////		m_fTimeRemainPunchIA = 0;
////
////
////	// the ia
////	if (m_pIALuttueur)
////	{
////		// define the strategy
////
////		// state leweto
////		// what happens?
////		if (m_pIALuttueur->isInStateLeweto())
////		{
////			// only attack when near other wrestler
////			if (m_pIALuttueur->getPosition().distance(m_pMainLutteur->getPosition()) <= 100)
////			{
////				// testing for the grab
////
////				// cooldown timer for punching
////				// the ia enter on this state
////				if (m_fTimeRemainPunchIA <= 0)
////				{
////					if (m_iNumberPunch >=2)
////					{
////						m_iNumberPunch = 0;
////						m_pIALuttueur->grab();
////						if (m_pMainLutteur)
////							m_pMainLutteur->grab();
////
////					}
////
////					else
////					{
////						m_pIALuttueur->punch();
////						m_fTimeRemainPunchIA = 1.0f;
////						m_iNumberPunch++;
////
////					}
////					
////				}	
////			}
////
////			// the ai is not on leweto position
////			else
////			{
////				//else
////				//{
////					moveAIForward();
////				//}
////			}
////		}
////
////
////
////		// state grab
////		else if (m_pIALuttueur->isInStateGrab())
////		{
////			// test for the best smasher
////
////			//m_pIALuttueur->setPositionX(m_pIALuttueur->getPositionX() + 10);
////
////			// this was onlu for test
////			if (m_pIALuttueur->m_iNumberSmash >= 150)
////				m_pIALuttueur->project();
////
////
////			// to make the ia project() 
////			// we use this technique above
////			// when energy goes to 0
////
////			// the output of grab
////		}
////		m_pIALuttueur->update(dt, m_pMainLutteur);
////	}
////}
//
//
//// move the ai
//void HelloWorld::moveAIForward()
//{
//	// exit when the wrestler is not on leweto
//	if (!m_pIALuttueur->isInStateLeweto())
//		return;
//
//
//	// checking for collision
//	if (m_pMainLutteur->getPosition().distance(m_pIALuttueur->getPosition()) >= 80)
//	{
//		m_pIALuttueur->moveForward();
//		//m_pMainLutteur->setPositionX(m_pMainLutteur->getPositionX() + 5);
//	}
//}
//
//
//
//// UI AND DESIGN
//
//
//// add the portrait of the left wrestler
//void HelloWorld::addIconWrestlerLeft()
//{
//	// size
//	Size visibleSize = Director::getInstance()->getVisibleSize();
//	Vec2 origin = Director::getInstance()->getVisibleOrigin();
//
//
//	// add "HelloWorld" splash screen"
//	auto sprite = Sprite::create("BayziarPIC.png");
//
//	// position the sprite on the center of the screen
//	sprite->setPosition(Vec2(visibleSize.width  *0.06 + origin.x, visibleSize.height *0.90 + origin.y));
//	//sprite->setPosition(Vec2(0, 0));
//	sprite->setScale(0.06);
//
//	// add the sprite as a child to this layer
//	this->addChild(sprite, 0);
//
//}
//
//
//// called for adding stamina
//// for the right wrestler
//void HelloWorld::addIconWrestlerRight()
//{
//	Size visibleSize = Director::getInstance()->getVisibleSize();
//	Vec2 origin = Director::getInstance()->getVisibleOrigin();
//
//
//	// add "HelloWorld" splash screen"
//	auto sprite = Sprite::create("MeukdoomPIC.png");
//
//	// position the sprite on the center of the screen
//	sprite->setPosition(Vec2(visibleSize.width  *0.95 + origin.x, visibleSize.height *0.90 + origin.y));
//	//sprite->setPosition(Vec2(0, 0));
//	sprite->setScale(0.06);
//
//	// add the sprite as a child to this layer
//	this->addChild(sprite, 0);
//
//
//}
//
//
//// called for adding stamina
//// for the left wrestler
//void HelloWorld::addIconStaminaLeft()
//{
//	Size visibleSize = Director::getInstance()->getVisibleSize();
//	Vec2 origin = Director::getInstance()->getVisibleOrigin();
//
//
//	// add "HelloWorld" splash screen"
//	//auto sprite = Sprite::create("Stamina.png");
//
//	// Create the loading bar
//	LoadingBar* loadingBar = LoadingBar::create("Stamina.png");
//	loadingBar->setTag(kTagLoadingBar1);
//	loadingBar->setDirection(LoadingBar::Direction::RIGHT);
//
//
//	// position the sprite on the center of the screen
//	loadingBar->setPosition(Vec2(visibleSize.width  *0.28 + origin.x, visibleSize.height *0.95 + origin.y));
//	//sprite->setPosition(Vec2(0, 0));
//	loadingBar->setScale(0.2f);
//
//	// add the sprite as a child to this layer
//	this->addChild(loadingBar, 10);
//
//	if (m_pMainLutteur)
//		loadingBar->setPercent(m_pMainLutteur->loadingBarEnergy);
//
//}
//
//
//// add a stamina icon for the right wrestler
//void HelloWorld::addIconStaminaRight()
//{
//
//	Size visibleSize = Director::getInstance()->getVisibleSize();
//	Vec2 origin = Director::getInstance()->getVisibleOrigin();
//
//
//	// Create the loading bar
//	LoadingBar* loadingBar = LoadingBar::create("Stamina.png");
//	loadingBar->setTag(kTagLoadingBar2);
//	loadingBar->setDirection(LoadingBar::Direction::LEFT);
//
//
//	// position the sprite on the center of the screen
//	loadingBar->setPosition(Vec2(visibleSize.width  *0.72 + origin.x, visibleSize.height *0.95 + origin.y));
//	//sprite->setPosition(Vec2(0, 0));
//	loadingBar->setScale(0.2f);
//
//
//	// add the sprite as a child to this layer
//	this->addChild(loadingBar, 10);
//
//	// slower th
//
//	if (m_pIALuttueur)
//		loadingBar->setPercent(m_pIALuttueur->loadingBarEnergy);
//
//}
//
//
//// add label for power
//void HelloWorld::addLabelPower()
//{
//	auto s = Director::getInstance()->getWinSize();
//
//	auto label1 = Label::createWithTTF("Power :", "fonts/Marker Felt.ttf", 24);
//
//
//	//label1->setString("power");
//	//label1->setFontName("Arial");
//
//	addChild(label1, 10, kTagLabel1);
//	label1->setPosition(Vec2( s.width *0.2  , (s.height / 6) * 5));
//	label1->setColor(Color3B::GREEN);
//	//label1->setPosition(Vec2(400, 400));
//
//}
//
//
//// update the label for power
//void HelloWorld::updateLabelPower(float dt)
//{
//	auto label1 = (LabelTTF*)getChildByTag(kTagLabel1);
//	char string[12] = { 0 };
//
//	sprintf(string, "Power :%d", (int)m_pIALuttueur->getPower());
//	//string.format("%d", (int)_time);
//	label1->setString(string);
//}
//
//
//// add label for damage 
//void HelloWorld::addLabelDamage()
//{
//
//}
//
//
//// update the label for damage
//void HelloWorld::updateLabelDamage(float dt)
//{
//
//}
//
//
//// add label for energy display
//void HelloWorld::addLabelEnergy()
//{
//	auto s = Director::getInstance()->getWinSize();
//	auto label1 = Label::createWithTTF("Energy :", "fonts/Marker Felt.ttf", 24);
//
//
//	//label1->setString("power");
//	//label1->setFontName("Arial");
//
//	addChild(label1, 10, kTagLabel2);
//	label1->setPosition(Vec2(s.width *0.2, (s.height / 6) * 4));
//	label1->setColor(Color3B::GREEN);
//
//}
//
//
//// update the label
//void HelloWorld::updateLabelEnergy(float dt)
//{
//
//	auto label1 = (LabelTTF*)getChildByTag(kTagLabel2);
//	char string[12] = { 0 };
//
//	sprintf(string, "Energy :%d", (int)m_pIALuttueur->getEnergy());
//	//string.format("%d", (int)_time);
//	label1->setString(string);
//}
//
//
//
//// loading bar
//void HelloWorld::addLoadingBar()
//{
//
//	// size
//	Size visibleSize = Director::getInstance()->getVisibleSize();
//	Vec2 origin = Director::getInstance()->getVisibleOrigin();
//
//
//	// Create the loading bar
//	LoadingBar* loadingBar = LoadingBar::create("sliderProgress.png");
//	loadingBar->setTag(kTagLoadingBar1);
//	loadingBar->setPosition(Vec2(visibleSize.width  *0.28 + origin.x, visibleSize.height *0.95 + origin.y));
//	loadingBar->setDirection(LoadingBar::Direction::RIGHT);
//	addChild(loadingBar, 12);
//	loadingBar->setScale(0.55);
//	loadingBar->setScaleX(0.33);
//
//	if (m_pIALuttueur)
//		loadingBar->setPercent((m_pIALuttueur->energie * 85) / 100);
//
//}
//
//
//float HelloWorld::getWidth()
//{
//
//	Size visibleSize = Director::getInstance()->getVisibleSize();
//
//	return visibleSize.width;
//}
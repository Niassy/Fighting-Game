#include "LoadingScreen.h"
#include "MainMenu.h"
#include "ui\UILoadingBar.h"


USING_NS_CC;
using namespace cocos2d::ui;


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


cocos2d::Scene * LoadingScreen::createScene()
{
	auto loading = Scene::create();
	auto layer = LoadingScreen::create();
	loading->addChild(layer);

	return loading;
}

bool LoadingScreen::init()
{
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
		CC_CALLBACK_1(LoadingScreen::menuCloseCallback, this));
	auto gotoMainMenu = MenuItemFont::create("Go to mainMenu", CC_CALLBACK_1(LoadingScreen::replaceCurrentScene, this));

	gotoMainMenu->setPosition(Vec2(origin.x + visibleSize.width - gotoMainMenu->getContentSize().width / 2,
		origin.y + gotoMainMenu->getContentSize().height));

	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width / 2,
		origin.y + closeItem->getContentSize().height / 2));

	// create menu, it's an autorelease object
	auto menu = Menu::create(/*gotoMainMenu,*/ closeItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);

	//create background

	auto bgc = Sprite::create("UI/ui1/BG.png");
	auto logo = Sprite::create("UI/ui1/LogoDD.png");
	//auto loadImg = Sprite::create("UI/ui1/Loading.png");
	logo->setScale(0.3);
	//loadImg->setScale(0.3);

	logo->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	//loadImg->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 5 + origin.y));

	this->addChild(bgc, 0);
	this->addChild(logo, 0);
	//this->addChild(loadImg, 0);


	// loading bar
	addLoadingBar();

	// the percent
	m_Percent = 0.0f;

	this->scheduleUpdate();

	return true;
}

void LoadingScreen::replaceCurrentScene(Ref* pSender)
{
	auto *pscene = MainMenu::createScene();
	auto *passage = TransitionMoveInR::create(1, pscene);
	Director::getInstance()->replaceScene(passage);
}
void LoadingScreen::menuCloseCallback(Ref* pSender)
{
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}


// go to the main menu
void LoadingScreen::goToMainMenu()
{
	auto newScene = MainMenu::createScene();
	Director::getInstance()->replaceScene(TransitionMoveInT::create(2, newScene));

}

// update the loading bar
void LoadingScreen::update(float dt)
{
	updateLoadingBar(dt);
}



// add a loadinf bar progress
void LoadingScreen::addLoadingBar()
{
	// size
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();


	// Create the loading bar
	LoadingBar* loadingBar = LoadingBar::create("sliderProgress.png");
	loadingBar->setTag(kTagLoadingBar1);
	//loadingBar->setPosition(Vec2(visibleSize.width  *0.28 + origin.x, visibleSize.height *0.95 + origin.y));
	loadingBar->setPosition(Vec2(visibleSize.width / 2.0f + origin.x, visibleSize.height / 10 + origin.y));

	loadingBar->setDirection(LoadingBar::Direction::LEFT);
	addChild(loadingBar, 12);
	//loadingBar->setScale(0.55);
	loadingBar->setScaleX(0.7);

}

void LoadingScreen::updateLoadingBar(float dt)
{
	LoadingBar* loadingBar = static_cast<LoadingBar*>(getChildByTag(kTagLoadingBar1));

	LoadingBar* loadingBar2 = static_cast<LoadingBar*>(getChildByTag(kTagLoadingBar2));

	m_Percent += 20 * dt;

	if (loadingBar)
	{
		loadingBar->setPercent(m_Percent);
	}


	// if reach 100 go to next scene

	if (m_Percent >= 100)
	{
		goToMainMenu();
	}

	

}

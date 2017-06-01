
#include "MainMenu.h"
#include "VsScreen.h"
//#include "SimpleAudioEngine.h"


//using namespace CocosDenshion;


//// defining tag for element
//#define TAG_MENU 0
//
//#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
//#define MUSIC_FILE        "music.mid"
//#elif (CC_TARGET_PLATFORM == CC_PLATFORM_BLACKBERRY || CC_TARGET_PLATFORM == CC_PLATFORM_LINUX )
//#define MUSIC_FILE        "background.ogg"
//#elif (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
//#define MUSIC_FILE        "background.wav"
//#else
//#define MUSIC_FILE        "background.mp3"
//#endif // CC_PLATFORM_WIN32
//
//


cocos2d::Scene * MainMenu::createScene()
{
	auto loading = Scene::create();
	auto layer = MainMenu::create();
	loading->addChild(layer);

	return loading;
}


//----------------------ctor------------------
MainMenu::MainMenu() :AbstractMenu()
{

}


//---------------dtor-------------------
MainMenu::~MainMenu()
{

}

bool MainMenu::init()
{
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	// start the menu
	Start();


}

//--------------------------- Instance ----------------------------------------
//
//   this class is a singleton
//-----------------------------------------------------------------------------
MainMenu* MainMenu::getInstance()
{
	static MainMenu instance;

	return &instance;
}

void MainMenu::Start()
{

	// only create when the layer is inactive


	if (isInactive())
	{

		// start music 

		// preload background music and effect

#if (CC_TARGET_PLATFORM   == CC_PLATFORM_WINRT)
		SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic(MUSIC_FILE);

		SimpleAudioEngine::sharedEngine()->playBackgroundMusic(MUSIC_FILE, true);
#endif

		AbstractScene::Start();
		// create the menuiteem and add the listener

		createItem();

	}



	else
	{
		if (isExited())
		{


		}

	}


	this->scheduleUpdate();


}

void MainMenu::update(float dt)
{

}

void MainMenu::Exit()
{
	setToExited();


#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT) || (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
	CCMessageBox("You pressed the close button. Windows Store Apps do not implement a close button.", "Alert");
#endif

	//CCDirector::sharedDirector()->end();

}


void MainMenu::Transit()
{

	// call an animation 
	// example : you can use a loading bar
	// that will be progress during loading game

}


void MainMenu::createItem()
{

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	/////////////////////////////
	// 2. add a menu item with "X" image, which is clicked to quit the program
	//    you may modify it.

	// add a "close" icon to exit the progress. it's an autorelease object
	auto closeItem = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(MainMenu::goToAboutPage, this));

	auto btnContinue = MenuItemImage::create(
		"UI/ui2/Continuer.png",
		"UI/ui2/Continuer.png",
		CC_CALLBACK_1(MainMenu::goToContinue, this));

	auto btnAbout = MenuItemImage::create("UI/ui2/Credits.png", "", CC_CALLBACK_1(MainMenu::goToAboutPage, this));

	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width / 2,
		origin.y + closeItem->getContentSize().height / 2));
	btnContinue->setScale(0.2);
	btnContinue->setPosition(Vec2(origin.x + visibleSize.width / 2,
		origin.y + btnContinue->getContentSize().height / 4));

	btnAbout->setScale(0.1);
	btnAbout->setPosition(Vec2(origin.x + visibleSize.width - btnAbout->getContentSize().width / 7,
		origin.y + btnAbout->getContentSize().height / 4));




	// create menu, it's an autorelease object
	auto menu = Menu::create(btnContinue, btnAbout, closeItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);

	//create background

	auto bgc1 = Sprite::create("UI/ui2/BG1.png");
	auto bgc2 = Sprite::create("UI/ui2/BG 2.png");
	auto logoDD = Sprite::create("UI/ui2/Logo DD.png");


	bgc2->setPosition(Vec2(origin.x + visibleSize.width - bgc2->getContentSize().width / 5,
		origin.y + bgc2->getContentSize().height / 2));

	logoDD->setScale(0.3);

	logoDD->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

	this->addChild(bgc2);
	this->addChild(bgc1, -2);
	this->addChild(logoDD, 2);


}
//void MainMenu::createItem()
//{
//	// Font Item
//	MenuItemFont *item1 = MenuItemFont::create("Game Mode", CC_CALLBACK_1(MainMenu::OnGameMode, this));
//
//	item1->setFontSizeObj(40);
//	item1->setFontName("Marker Felt");
//
//
//
//
//	// Font Item
//	MenuItemFont *item2 = MenuItemFont::create("Tutorial", CC_CALLBACK_1(MainMenu::onTutorial, this));
//
//	item2->setFontSizeObj(40);
//	item2->setFontName("Marker Felt");
//
//
//	// Font Item
//	MenuItemFont *item3 = MenuItemFont::create("Options", CC_CALLBACK_1(MainMenu::OnOptions, this));
//
//	item3->setFontSizeObj(40);
//	item3->setFontName("Marker Felt");
//
//
//	// Font Item
//	MenuItemFont *item4 = MenuItemFont::create("Exit", CC_CALLBACK_1(MainMenu::onExit, this));
//
//	item4->setFontSizeObj(40);
//	item4->setFontName("Marker Felt");
//
//	Menu* menu = Menu::create(item1, item2, item3, item4, NULL);
//	menu->alignItemsVertically();
//
//
//	addChild(menu);
//
//}

//
//void MainMenu::createButtonExit()
//{
//
//}


void MainMenu::goToContinue(cocos2d::Ref* pSender)
{
	auto newScene = VsScreen::createScene();
	Director::getInstance()->replaceScene(TransitionFadeTR::create(2, newScene));
}

void MainMenu::goToAboutPage(cocos2d::Ref* pSender)
{

}

//
//
////----------------function for label input or button------------------
////
////--------------------------------------------------------------------
//void MainMenu::OnGameMode(CCObject* pSender)
//{
//}
//
//
//void MainMenu::onTutorial(CCObject* pSender)
//{
//
//}
//
//void MainMenu::OnOptions(CCObject* pSender)
//{
//
//}
//
//
//void MainMenu::onExit(CCObject* pSender)
//{
//	Exit();
//}

#include "GameScene.h"
#include "LoadingScreen.h"



USING_NS_CC;
using namespace cocos2d::ui;

Scene* GameScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = GameScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool GameScene::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();


	// add "HelloWorld" splash screen"
	auto bgc = Sprite::create("UI/ui1/BG.png");
	auto logo = Sprite::create("logoImpakt.png");


	// position the sprite on the center of the screen
	logo->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	logo->setScale(CC_CONTENT_SCALE_FACTOR() * 0.2);

	// add the sprite as a child to this layer
	this->addChild(bgc, 0);
	this->addChild(logo, 0);

	//auto *pscene = LoadingScreen::createScene();
	//auto *passage = TransitionMoveInR::create(3, pscene);
	//Director::getInstance()->replaceScene(passage);

	//scene transition
	scheduleOnce(CC_SCHEDULE_SELECTOR( GameScene::goToLoadingScreen), 3.0f);

	return true;
}


void GameScene::update(float dt)
{

}

void GameScene::goToLoadingScreen(float dt)
{
	auto newScene = LoadingScreen::createScene();
	Director::getInstance()->replaceScene(TransitionMoveInT::create(1, newScene));

}
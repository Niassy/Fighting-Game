#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"

class GameScene : public cocos2d::Layer
{

private:


public:

	static cocos2d::Scene* createScene();

	// implement the "static create()" method manually
	CREATE_FUNC(GameScene);


	virtual bool init();

private:

	void update(float dt);

	void goToLoadingScreen(float dt);

	
	// a selector callback
	//void menuCloseCallback(cocos2d::Ref* pSender);


};

#endif // __HELLOWORLD_SCENE_H__

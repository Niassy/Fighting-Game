#ifndef __LOADING_SCREEN_H__
#define __LOADING_SCREEN_H__
#include "cocos2d.h"


class LoadingScreen : public cocos2d::Layer
{

private:

	float m_Percent;

public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	// a selector callback
	void menuCloseCallback(cocos2d::Ref* pSender);
	void replaceCurrentScene(Ref* pSender);

	CREATE_FUNC(LoadingScreen);


	// go to the main menu
	void goToMainMenu();


	// add a loadinf bar progress
	void addLoadingBar();

	void updateLoadingBar(float ft);

	void update(float dt);
};
#endif // __LOADING_SCREEN_H__
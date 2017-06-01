#include "Animate.h"

USING_NS_CC;

void AnimationUtil::animate(char* file, int nbFrames, float delay, cocos2d::Sprite* sprite, cocos2d::ActionInterval* animationAction, bool repeat)
{
	if (sprite == nullptr)
		return ;

	if (nbFrames <= 0)
		return;

	if (nbFrames == 1)
	{
		sprite->setTexture(file);
		return;
	}

	auto animation = Animation::create();
	for (int i = 1; i<nbFrames + 1; i++)
	{
		char szName[100] = { 0 };
		sprintf(szName,file, i);
		animation->addSpriteFrameWithFile(szName);
	}

	if (delay <= 0)
	{
		delay = 1.0f;
	}

	// should last 2.8 seconds. And there are 14 frames.
	animation->setDelayPerUnit(delay / nbFrames);
	animation->setRestoreOriginalFrame(false);

	// no repeat animation
	// the animation finishes when the frame are finished
	// no loop
	if (!repeat)
	{
		auto actionAnimOneLoop = Animate::create(animation);

		// before you must check the repeat bool
		sprite->runAction(actionAnimOneLoop);

		actionAnimOneLoop->setTag(0);
		

		//animationAction = static_cast<Animate*>(animationAction);
		animationAction = actionAnimOneLoop;
	}

	// loop animation
	else
	{
		auto actionAnimLoop = Animate::create(animation);
		auto repeat = RepeatForever::create(actionAnimLoop);

		// before you must check the repeat bool
		sprite->runAction(repeat);

		repeat->setTag(1);


		animationAction = repeat;
	}

	//auto repeat = RepeatForever::create(action);

	//m_pActionLewto = repeat;

	//runAction(repeat);

	//setScale(0.2);
}
#ifndef _ANIMATION_


#define _ANIMATION_

#include "cocos2d.h"


#include <string>

class AnimationUtil
{

public:

	static void animate(char* file, int nbFrames, float delay, cocos2d::Sprite* sprite, cocos2d::ActionInterval* action = nullptr, bool repeat = false);

};

#endif
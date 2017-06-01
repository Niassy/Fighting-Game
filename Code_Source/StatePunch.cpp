#include "StatePunch.h"
#include "Lutteur.h"
#include "Animate.h"
#include "ressouces_file.h"
#include "GameWorld.h"

void StatePunch::Enter(Lutteur* lutteur)
{
	//lutteur->setScale(0.2f);
	//lutteur->setTexture("Block_Gauche/Image.png");

	m_fTimeElapsed = 0;

	m_itype = type_Punch;

	lutteur->setScale(CC_CONTENT_SCALE_FACTOR() * 0.15f);


	// check for the orientation of the wrestler
	if (lutteur->getOrientation() == Lutteur::orientation::left)
	{
		AnimationUtil::animate(s_PathPunch, 7, 0.35f, lutteur, m_pAnim, false);
	}
	
	else
	{
		AnimationUtil::animate(s_PathPunch1, 7, 0.35f, lutteur, m_pAnim, false);

	}

	//lutteur->m_pGame->animateFXPunch(cocos2d::Vec2(200, 200));

	
}

void  StatePunch::Execute(Lutteur* lutteur, Lutteur* other, float dt)
{
	m_fTimeElapsed += dt;

	/*if (m_fTimeElapsed >= 0.1 )
	{
		// need more rigorous test
		if (!other->isDamaged())
			other->setDamaged(true);
	}

	if (other->isDamaged())
		other->takePunch();*/



	// test case when the two wrestler are on
	// the punch state


	float dist = lutteur->getPosition().distance(other->getPosition());

	if (other->isInStatePunch())
	{
		if (other->getCurrentStateElapsedTime() > lutteur->getCurrentStateElapsedTime())
		{

			if ( dist <= lutteur->getDistanceFromPunch() )
				return;
			// punch animation
			// 
			if (other->getActionByTag(0) && other->getActionByTag(0)->isDone())
			{
				lutteur->takePunch();
			}

			//else
			//	return;
		}
	}

	if (other->isInStateUppercut())
	{
		
			if (dist <= lutteur->getDistanceFromUppercut())
				return;
			// punch animation
			// 
			if (other->getActionByTag(0) && other->getActionByTag(0)->isDone())
			{
				lutteur->takeUpperCut();
			}

			//else
			//	return;
		//}
	}



	// This is an animation that is not looped
	// so the animation is deleted when it finished
	if (lutteur->getActionByTag(0) == nullptr)
	{
		// test for impact

		//if (other->getPosition().distance(lutteur->getPosition()) <= 80)
			//other->takePunch();

		if (lutteur->getDistanceFromPunch(other)  && !other->isInStateBlock())
			other->takePunch();

		//lutteur->setPositionX(lutteur->getPositionX() + 1);
		lutteur->leweto();
	}
}

void  StatePunch::Exit(Lutteur* lutteur)
{
	// stop the animation

	//if (m_pAnim != nullptr)
	//{
		//lutteur->stopActionByTag(0);

	//}

}
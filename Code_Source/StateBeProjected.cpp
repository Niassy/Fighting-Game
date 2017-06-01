#include "StateBeProjected.h"
#include "Lutteur.h"
#include "Animate.h"
#include "ressouces_file.h"
#include "GameWorld.h"

void StateBeProjection::Enter(Lutteur* lutteur)
{
	//lutteur->setScale(0.2f);
	//lutteur->setTexture("Block_Gauche/Image.png");


	m_fTimeElapsed = 0;

	m_itype = type_BeProjected;

	//lutteur->setScale(0.15);
	//lutteur->setScale(CC_CONTENT_SCALE_FACTOR() * 0.15f);

	lutteur->setScale(CC_CONTENT_SCALE_FACTOR() * 0.13f);


	// GET THE RANDOM
	float rand = CCRANDOM_0_1();

	// check for the orientation of the wrestler
	if (lutteur->getOrientation() == Lutteur::orientation::left)
	{
		if (rand <= 0.5f)
			AnimationUtil::animate(s_PathBeProjection1, 4, 2.8f, lutteur, m_pAnim, false);

		else
			AnimationUtil::animate(s_PathBeProjection3, 3, 2.1f, lutteur, m_pAnim, false);

	}

	else
	{
		if (rand <= 0.5f)
			AnimationUtil::animate(s_PathBeProjection2, 4, 2.8f, lutteur, m_pAnim, false);

		else
			AnimationUtil::animate(s_PathBeProjection4, 3, 2.1f, lutteur, m_pAnim, false);

	}

	//lutteur->setPositionY(lutteur->getPositionY() + 30);

	//lutteur->setPositionY(lutteur->getPositionY() - 10);
	lutteur->setPositionY(lutteur->getPositionY() - GameWorld::getHeight() / 45.71f);
}

void  StateBeProjection::Execute(Lutteur* lutteur, Lutteur* other, float dt)
{

	m_fTimeElapsed += dt;

	// This is an animation that is not looped
	// so the animation is deleted when it finished
	if (lutteur->getActionByTag(0) == nullptr)
	{


		// test for impact

		//if (other->getPosition().distance(lutteur->getPosition()) <= 100)
		//other->takePunch();

		//lutteur->setPositionX(lutteur->getPositionX() + 1);

		if (m_fTimeElapsed >= 6.0f)
		{
			lutteur->beDefeated();

			lutteur->m_pGame->arbiterFinish();
		}
	}

	else
	{
		//lutteur->setPositionY(lutteur->getPositionY() +0.5f);
		//lutteur->setPositionX(lutteur->getPositionX() + 0.5f);

	}
}

void  StateBeProjection::Exit(Lutteur* lutteur)
{
	// stop the animation

	//if (m_pAnim != nullptr)
	//{
	//lutteur->stopActionByTag(0);

	//}

}
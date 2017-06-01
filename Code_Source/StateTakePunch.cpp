#include "StateTakePunch.h"
#include "Lutteur.h"
#include "Animate.h"
#include "ressouces_file.h"
#include "GameWorld.h"


void StateTakePunch::Enter(Lutteur* lutteur)
{

	// take damage
	lutteur->receiveDamage(10);


	// update also the loading bar
	lutteur->loadingBarEnergy -= 7;


	if (lutteur->loadingBarEnergy <= 0)
		lutteur->loadingBarEnergy = 0;


	// start the timer
	m_fTimeElapsed = 0;

	//lutteur->setScale(0.2f);
	//lutteur->setTexture("Block_Gauche/Image.png");

	lutteur->setScale(CC_CONTENT_SCALE_FACTOR() * 0.15f);


	// check for the orientation of the wrestler
	if (lutteur->getOrientation() == Lutteur::orientation::left)
	{
		AnimationUtil::animate(s_PathTakingPunch, 1, 0.0f, lutteur, m_pAnim, false);
	}

	else
	{
		AnimationUtil::animate(s_PathTakingPunch1, 1, 0.0f, lutteur, m_pAnim, false);

	}


	if (!lutteur->isVeryLowlyHealth())
		////////////////////// fx
		// animate fx
		lutteur->m_pGame->animateFXPunch(cocos2d::Vec2(lutteur->getPosition().x, lutteur->getPosition().y * 1.5f));

}

void  StateTakePunch::Execute(Lutteur* lutteur, Lutteur* other,float dt)
{

	//lutteur->setPositionX(lutteur->getPositionX() + 1);

	m_fTimeElapsed += dt;


	if (m_fTimeElapsed >= 0.20f)
	{

		if (lutteur->isVeryLowlyHealth() )
		{
			lutteur->beEtourdi();
			return;
		}


		// the opponent go to lewreto state
		// if he is not suck
		lutteur->leweto();
	}
	

	// This is an animation that is not looped
	// so the animation is deleted when it finished
	//if (lutteur->getActionByTag(0) == nullptr)
	//{
		//lutteur->setPositionX(lutteur->getPositionX() + 1);
		//lutteur->leweto();
		//}
}

void  StateTakePunch::Exit(Lutteur* lutteur)
{
	// stop the animation

	//if (m_pAnim != nullptr)
	//{
	//lutteur->stopActionByTag(0);

	//}


}
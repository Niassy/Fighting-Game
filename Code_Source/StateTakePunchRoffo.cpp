#include "StateTakePunchRoffo.h"
#include "Lutteur.h"
#include "Animate.h"
#include "ressouces_file.h"
#include "GameWorld.h"


void StateTakePunchRoffo::Enter(Lutteur* lutteur)
{

	m_itype = type_TakePunchRoffo;

	// take damage
	lutteur->receiveDamage(5);

	m_vOldPos = lutteur->getPosition();


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
		AnimationUtil::animate(s_PathTakingPunchRoffo, 1, 0.0f, lutteur, m_pAnim, false);
	}

	else
	{
		AnimationUtil::animate(s_PathTakingPunchRoffo1, 1, 0.0f, lutteur, m_pAnim, false);
	}

	if (!lutteur->isVeryLowlyHealth())
		////////////////////// fx
		// animate fx
		lutteur->m_pGame->animateFXPunch(cocos2d::Vec2(lutteur->getPosition().x, lutteur->getPosition().y * 1.5f));

	lutteur->setPositionY(lutteur->getPositionY() - GameWorld::getHeight() / 10.67f);


}

void  StateTakePunchRoffo::Execute(Lutteur* lutteur, Lutteur* other, float dt)
{
	//lutteur->setPositionX(lutteur->getPositionX() + 1);

	m_fTimeElapsed += dt;

	if (m_fTimeElapsed >= 0.20f)
	{
		if (lutteur->isVeryLowlyHealth())
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

void  StateTakePunchRoffo::Exit(Lutteur* lutteur)
{

	lutteur->setPosition(m_vOldPos);
	// stop the animation

	//if (m_pAnim != nullptr)
	//{
	//lutteur->stopActionByTag(0);

	//}


}
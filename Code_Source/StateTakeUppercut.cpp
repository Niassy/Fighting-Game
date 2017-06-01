#include "StateTakeUppercut.h"
#include "Lutteur.h"
#include "Animate.h"
#include "ressouces_file.h"
#include "GameWorld.h"
void StateTakeUppercut::Enter(Lutteur* lutteur)
{

	// start the timer
	m_fTimeElapsed = 0;

	//lutteur->setScale(0.2f);
	//lutteur->setTexture("Block_Gauche/Image.png");

	lutteur->setScale(CC_CONTENT_SCALE_FACTOR() * 0.15f);

	// update also the loading bar
	lutteur->loadingBarEnergy -= 7;


	if (lutteur->loadingBarEnergy <= 0)
		lutteur->loadingBarEnergy = 0;


	// check for the orientation of the wrestler
	if (lutteur->getOrientation() == Lutteur::orientation::left)
	{
		AnimationUtil::animate(s_PathTakingUppercut, 1, 0.0f, lutteur, m_pAnim, false);
		////////////////////// fx
		// animate fx
		lutteur->m_pGame->animateFXUppercutGauche(cocos2d::Vec2(lutteur->getPosition().x *1.2f, lutteur->getPosition().y * 1.6f));

	}

	else
	{
		AnimationUtil::animate(s_PathTakingUppercutDroite, 1, 0.0f, lutteur, m_pAnim, false);

		////////////////////// fx
		// animate fx
		lutteur->m_pGame->animateFXUppercutDroite(cocos2d::Vec2(lutteur->getPosition().x * 1.2f, lutteur->getPosition().y * 1.6f));


	}


	

}

void  StateTakeUppercut::Execute(Lutteur* lutteur, Lutteur* other, float dt)
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

void  StateTakeUppercut::Exit(Lutteur* lutteur)
{
	// stop the animation

	//if (m_pAnim != nullptr)
	//{
	//lutteur->stopActionByTag(0);

	//}
}
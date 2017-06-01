#include "StateBlock.h"
#include "Lutteur.h"
#include "Animate.h"
#include "ressouces_file.h"

void StateBlock::Enter(Lutteur* lutteur)
{
	//lutteur->setScale(0.2f);
	//lutteur->setTexture("Block_Gauche/Image.png");

	m_fTimeElapsed = 0;

	m_itype = type_Block;

	lutteur->setScale(CC_CONTENT_SCALE_FACTOR() * 0.15f);


	// check for the orientation of the wrestler
	if (lutteur->getOrientation() == Lutteur::orientation::left)
	{
		AnimationUtil::animate(s_PathBlockGauche, 1, 0.0f, lutteur, m_pAnim, false);
	}

	else
	{
		AnimationUtil::animate(s_PathBlockDroite, 1, 0.0f, lutteur, m_pAnim, false);
	}

}

void  StateBlock::Execute(Lutteur* lutteur, Lutteur* other, float dt)
{
	m_fTimeElapsed += dt;

	float dist = lutteur->getPosition().distance(other->getPosition());


	if (m_fTimeElapsed >= 0.20f)
	{
		// the opponent go to lewreto state
		// if he is not suck
		lutteur->leweto();
	}



	// This is an animation that is not looped
	// so the animation is deleted when it finished
	//if (lutteur->getActionByTag(0) == nullptr)
	//{
	//	// test for impact

	//	//if (other->getPosition().distance(lutteur->getPosition()) <= 80)
	//	//other->takePunch();


	//	//lutteur->setPositionX(lutteur->getPositionX() + 1);
	//	lutteur->leweto();
	//}
}

void  StateBlock::Exit(Lutteur* lutteur)
{
	// stop the animation

	//if (m_pAnim != nullptr)
	//{
	//lutteur->stopActionByTag(0);

	//}

}
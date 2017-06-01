#include "StatePunchRoffo.h"
#include "Lutteur.h"
#include "Animate.h"
#include "ressouces_file.h"
#include "GameWorld.h"

void StatePunchRoffo::Enter(Lutteur* lutteur)
{
	//lutteur->setScale(0.2f);
	//lutteur->setTexture("Block_Gauche/Image.png");

	m_vOldPos = lutteur->getPosition();

	m_fTimeElapsed = 0;

	m_itype = type_TakePunchRoffo;

	lutteur->setScale(CC_CONTENT_SCALE_FACTOR() * 0.15f);


	// check for the orientation of the wrestler
	if (lutteur->getOrientation() == Lutteur::orientation::left)
	{
		AnimationUtil::animate(s_PathPunchRoffo, 2, 0.25f, lutteur, m_pAnim, false);
	}

	else
	{
		AnimationUtil::animate(s_PathPunchRoffo1, 2, 0.25f, lutteur, m_pAnim, false);

	}

	lutteur->setPositionY(lutteur->getPositionY() - GameWorld::getHeight() / 10.67f);
}

void  StatePunchRoffo::Execute(Lutteur* lutteur, Lutteur* other, float dt)
{
	m_fTimeElapsed += dt;



	// This is an animation that is not looped
	// so the animation is deleted when it finished
	if (lutteur->getActionByTag(0) == nullptr)
	{
		// test for impact

		//if (other->getPosition().distance(lutteur->getPosition()) <= 80)
		//other->takePunch();

		//if (lutteur->getDistanceFromPunch(other) && !other->isInStateBlock())
		//other->takePunchRoffo();

		//lutteur->setPositionX(lutteur->getPositionX() + 1);
		lutteur->leweto();
	}
}

void  StatePunchRoffo::Exit(Lutteur* lutteur)
{

	lutteur->setPosition(m_vOldPos);
	// stop the animation

	//if (m_pAnim != nullptr)
	//{
	//lutteur->stopActionByTag(0);

	//}

}
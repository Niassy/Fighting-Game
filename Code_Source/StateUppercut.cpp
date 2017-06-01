#include "StateUppercut.h"
#include "Lutteur.h"
#include "Animate.h"
#include "ressouces_file.h"

void StateUppercut::Enter(Lutteur* lutteur)
{
	//lutteur->setScale(0.2f);
	//lutteur->setTexture("Block_Gauche/Image.png");

	lutteur->setScale(CC_CONTENT_SCALE_FACTOR() * 0.15f);

	m_itype = type_Uppercut;

	
	// start the timer
	m_fTimeElapsed = 0;



	// check for the orientation of the wrestler
	if (lutteur->getOrientation() == Lutteur::orientation::left)
	{
		AnimationUtil::animate(s_PathUppercut, 9, 0.35f, lutteur, m_pAnim, false);
	}

	else
	{
		AnimationUtil::animate(s_PathUppercut1, 9, 0.35f, lutteur, m_pAnim, false);
	}

}

void  StateUppercut::Execute(Lutteur* lutteur, Lutteur* other, float dt)
{
	m_fTimeElapsed += dt;

	float dist = lutteur->getPosition().distance(other->getPosition());


	//if (other->isInStatePunch() )
	//{
	//	if (other->getCurrentStateElapsedTime() > lutteur->getCurrentStateElapsedTime())
	//	{

	//		if (dist <= lutteur->getDistanceFromPunch())
	//			return;
	//		// punch animation
	//		// 
	//		if (other->getActionByTag(0) && other->getActionByTag(0)->isDone())
	//		{
	//			lutteur->takePunch();
	//		}

	//		else
	//			return;
	//	}
	//}


	//if (other->isInStateUppercut())
	//{
	//	if (other->getCurrentStateElapsedTime() > lutteur->getCurrentStateElapsedTime())
	//	{

	//		if (dist <= lutteur->getDistanceFromUppercut())
	//			return;
	//		// punch animation
	//		// 
	//		if (other->getActionByTag(0) && other->getActionByTag(0)->isDone())
	//		{
	//			lutteur->takeUpperCut();
	//		}

	//		else
	//			return;
	//	}
	//}


	// This is an animation that is not looped
	// so the animation is deleted when it finished
	if (lutteur->getActionByTag(0) == nullptr)
	{
		//if (other->getPosition().distance(lutteur->getPosition()) <= 80)
			//other->takeUpperCut();

		if (lutteur->getDistanceFromUppercut(other))
			other->takeUpperCut();

		//lutteur->setPositionX(lutteur->getPositionX() + 1);
		lutteur->leweto();
	}
}

void StateUppercut::Exit(Lutteur* lutteur)
{
	// stop the animation

	//if (m_pAnim != nullptr)
	//{
	//lutteur->stopActionByTag(0);

	//}


}
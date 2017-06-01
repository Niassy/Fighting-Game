#include "StateLeweto.h"
#include "Lutteur.h"
#include "Animate.h"
#include "ressouces_file.h"
#include "Type_State.h"

USING_NS_CC;

/*

When you enter this state,
the wrestler is in the position
// leweto
*/
void StateLeweto::Enter(Lutteur* lutteur)
{
	m_itype = type_Leweto;
	m_fTimeElapsed = 0;


	//lutteur->setScale(CC_CONTENT_SCALE_FACTOR() * 0.2f);
	lutteur->setScale(CC_CONTENT_SCALE_FACTOR() * 0.15f);

	//lutteur->setTexture("Block_Gauche/Image.png");

	// check for the orientation of the wrestler
	if (lutteur->getOrientation() == Lutteur::orientation::left)
	{
		//AnimationUtil::animate(s_PathLeweto, 9, 0.9f, lutteur,m_pRepeat, true);
		AnimationUtil::animate(s_PathLeweto, 2, 0.2f, lutteur,m_pRepeat, true);
	}

	else
	{
	   //AnimationUtil::animate(s_PathLeweto1, 9, 0.9f, lutteur, m_pRepeat, true);
		AnimationUtil::animate(s_PathLeweto1, 2, 0.2f, lutteur, m_pRepeat, true);
	}

}

void StateLeweto::Execute(Lutteur* lutteur, Lutteur* other, float dt)
{
	m_fTimeElapsed += dt;

	int hp1 = lutteur->loadingBarEnergy;
	int hp2 = other->loadingBarEnergy;

	float dist = lutteur->getPosition().distance(other->getPosition());

	// posseded
	if (lutteur->m_bPosseded == true)
	{
		if (m_fTimeElapsed <= 0.6f)
			return;

		// need to punch
		// 
		if (lutteur->needToPunch(other))
		{
			lutteur->punch();
			return;
		}


		// distance from grab reached
		// so can grab
		if (lutteur->needToGrab(other))
		{
			if (other->isInStateLeweto())
				//return;
			{

				lutteur->grab();
				other->grab();
				return;
			}

			if (other->isInStateEtourdi())
			{
				lutteur->project();
				other->beProjected();
				return;

			}
		}

		if (lutteur->needToMoveForwardPunch(other))
		{
			lutteur->moveForward(Lutteur::getDistanceFromPunch());
			return;
		}

		if (lutteur->needToMoveForwardGrab(other))
		{
			lutteur->moveForward(Lutteur::getDistanceFromGrab());
			return;
		}

		if (lutteur->needToFlee(other))
		{
			if (lutteur->isFromDistanceFlee(other))
				return;

			if (lutteur->collideWithRightScreen())
			{
				// want to block
				lutteur->block();
				return;
			}

			lutteur->moveDownWard(Lutteur::getDistanceFlee());
			return;
		}

		else
		{
			// want to block
			/*if (lutteur->needToBlock(other))
			{
				lutteur->block();
			}*/
		}

	}
}

//// leweto 1s method
//void StateLeweto::Execute(Lutteur* lutteur, Lutteur* other, float dt)
//{
//	m_fTimeElapsed += dt;
//	//lutteur->setPositionX(lutteur->getPositionX() + 1);
//
//	// checking for collision
//
//	if (lutteur->m_bPosseded == true)
//	{
//		// distance from punch or grab
//		if (lutteur->getPosition().distance(other->getPosition()) >= 80)
//		{
//			int hp = lutteur->getEnergy();
//
//			int hp1 = other->getEnergy();
//
//			if (hp >= 50)
//				lutteur->moveForward();
//
//			else if (hp <=50 &&  hp1 < hp)
//				lutteur->moveForward();
//
//			else  if (hp <50)
//				lutteur->moveDownWard();
//
//			//m_pMainLutteur->setPositionX(m_pMainLutteur->getPositionX() + 5);
//		}
//
//
//		// the wrestler is close to punch
//		else
//		{
//			int hp = lutteur->getEnergy();
//
//			// only grab when energy < 50
//			int hp1 = other->getEnergy();
//
//			if (hp <= 50)
//			{
//				lutteur->moveDownWard();
//			}
//
//
//			if (hp1 <= 30)
//			{
//				if (m_fTimeElapsed >= 1.8f)
//				{
//
//					lutteur->grab();
//					other->grab();
//				}
//			}
//			
//
//			// punch
//			else
//			{
//				if (m_fTimeElapsed >= 0.60f)
//				lutteur->punch();
//			}
//
//		}
//	}
//}

void StateLeweto::Exit(Lutteur* lutteur)
{
	// stop the animation
	//if (m_pRepeat != nullptr)
	if (lutteur->getActionByTag(1))
		lutteur->stopActionByTag(1);

}
#include "StateMoveForWard.h"
#include "Lutteur.h"
#include "Animate.h"
#include "ressouces_file.h"
#include "Type_State.h"
#include "GameWorld.h"


/*

When you enter this state,
the wrestler is in the position
// moving by doing leweto
*/
void StateMoveForward::Enter(Lutteur* lutteur)
{
	m_fTimerFX = 0.3f;

	//lutteur->setScale(0.2f);
	lutteur->setScale(CC_CONTENT_SCALE_FACTOR() * 0.15f);

	//lutteur->setTexture("Block_Gauche/Image.png");

	m_itype = type_MoveForward;

	m_fTimeElapsed = 0;
	// check for the orientation of the wrestler
	if (lutteur->getOrientation() == Lutteur::orientation::left)
	{
		AnimationUtil::animate(s_PathMoveForward, 12, 1.2f, lutteur, /*m_pAnim*/m_pRepeat, /*false*/true);
	}

	else
	{
		AnimationUtil::animate(s_PathMoveForward1, 12, 1.2f, lutteur,/* m_pAnim*/m_pRepeat, /*false*/true);
	}


	////////////////////// fx
	// animate fx
	lutteur->m_pGame->animateFXWalk(cocos2d::Vec2(lutteur->getPosition().x, lutteur->getPosition().y * 0.5f));

}


void StateMoveForward::Execute(Lutteur* lutteur, Lutteur* other, float dt)
{
	m_fTimeElapsed += dt;

	m_fTimerFX -= dt;

	if (m_fTimerFX <= 0)
	{
		m_fTimerFX = 0.3f;

		////////////////////// fx
		// animate fx
		lutteur->m_pGame->animateFXWalk(cocos2d::Vec2(lutteur->getPosition().x, lutteur->getPosition().y * 0.5f));
	}


	//if (m_fTimeElapsed >= )
	//lutteur->m_pGame->animateFXWalk(cocos2d::Vec2(lutteur->getPosition().x, lutteur->getPosition().y * 1.0f));

	if (lutteur->isOrientedLeft())
		lutteur->setPositionX(lutteur->getPositionX() + 0.5);
		
	else
	     lutteur->setPositionX(lutteur->getPositionX() - 0.5);

    // controlled by ai		
	if (lutteur->m_bPosseded == true)
	{
		/*if (lutteur->getPosition().distance(other->getPosition()) < 80)   // dist for punch
		{
			lutteur->leweto();
		}*/

		if (lutteur->getPosition().distance(other->getPosition()) < m_fDistanceFromOpponent)
		{
			lutteur->leweto();
		}
	}

	// player
	else
	{
		if (lutteur->m_pGame->getInputDaan1() == true)
		{
			if (lutteur->getPosition().distance(other->getPosition()) < m_fDistanceFromOpponent)
			{
				lutteur->leweto();
				
			}
			return;
		}

		float dist = lutteur->getPosition().distance(m_vOldPos);

		if (dist >= 15.0f)
		{
			// stop moving
			lutteur->leweto();
		}
	}
			
}


//// 1st method
//void StateMoveForward::Execute(Lutteur* lutteur, Lutteur* other, float dt)
//{
//	if (lutteur->isOrientedLeft())
//		lutteur->setPositionX(lutteur->getPositionX() + 0.5);
//
//	else
//		lutteur->setPositionX(lutteur->getPositionX() - 0.5);
//
//
//	// controlled by ai
//	
//	 if (lutteur->m_bPosseded == true)
//	 {
//		// distance from punch or grab
//		if (lutteur->getPosition().distance(other->getPosition()) < 80)
//		{
//			
//			// only grab when energy < 50
//			int hp1 = other->getEnergy();
//			if (hp1 <= 50)
//			{
//				lutteur->grab();
//				other->grab();
//			}
//
//
//			// punch
//			else
//			{
//				lutteur->leweto();
//			}
//		}
//		
//	}
//
//	// distance limit
//	//if (other->getPosition().distance(lutteur->getPosition()) <= 80)
//		//other->takePunch();
//	
//	//if (!lutteur->isPosseded())
//	//{
//		if (lutteur->getActionByTag(0) == nullptr)
//			lutteur->leweto();
//
//	//}
//
//}

void StateMoveForward::Exit(Lutteur* lutteur)
{
	// stop the animation
	//if (m_pRepeat != nullptr)
	if (lutteur->getActionByTag(1))
		lutteur->stopActionByTag(1);

}
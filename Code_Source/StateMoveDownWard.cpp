#include "StateMoveDownWard.h"
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
void StateMoveDownWard::Enter(Lutteur* lutteur)
{
	m_fTimerFX = 0.3f;

	m_fTimeElapsed = 0.0f;

	//lutteur->setScale(0.2f);
	lutteur->setScale(CC_CONTENT_SCALE_FACTOR() * 0.15f);

	//lutteur->setTexture("Block_Gauche/Image.png");

	m_itype = type_MoveDownward;

	// check for the orientation of the wrestler
	if (lutteur->getOrientation() == Lutteur::orientation::left)
	{
		AnimationUtil::animate(s_PathMoveForward, 12, 1.2f, lutteur, m_pRepeat, true);
	}

	else
	{
		AnimationUtil::animate(s_PathMoveForward1, 12, 1.2f, lutteur, m_pRepeat, true);
	}

}

void StateMoveDownWard::Execute(Lutteur* lutteur, Lutteur* other, float dt)
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

	if (lutteur->isOrientedLeft())
	{

		lutteur->setPositionX(lutteur->getPositionX() - 0.5);
	}

	else
	{


		if (lutteur->collideWithRightScreen())
		{
			lutteur->leweto();
			return;
		}

		lutteur->setPositionX(lutteur->getPositionX() + 0.5);
	}

	// controlled by ai
	
	 if (lutteur->m_bPosseded == true)
	 {
		// distance from punch or grab
		if (lutteur->getPosition().distance(other->getPosition()) >= m_fDistanceFromOpponent)
		{
			lutteur->leweto();

		}
		
	}

	 else
	 {
		 float dist = lutteur->getPosition().distance(m_vOldPos);

		 if (dist >= 15.0f)
		 {
			 // stop moving
			 lutteur->leweto();
		 }
	 }

	// distance limit
	//if (other->getPosition().distance(lutteur->getPosition()) <= 80)
		//other->takePunch();
	
	//if (!lutteur->isPosseded())
	//{
		//if (lutteur->getActionByTag(0) == nullptr)
			//lutteur->leweto();

	//}

}

void StateMoveDownWard::Exit(Lutteur* lutteur)
{
	// stop the animation
	//if (m_pRepeat != nullptr)
	if (lutteur->getActionByTag(1))
		lutteur->stopActionByTag(1);

}
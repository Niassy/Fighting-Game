#include "StateDefeat.h"
#include "Lutteur.h"
#include "Animate.h"
#include "ressouces_file.h"


void StateDefeat::Enter(Lutteur* lutteur)
{
	lutteur->setScale(CC_CONTENT_SCALE_FACTOR() * 0.15f);


	m_itype = type_Defeat;

	// check for the orientation of the wrestler
	if (lutteur->getOrientation() == Lutteur::orientation::left)
	{
		AnimationUtil::animate(s_PathDefeat1, 2, 1.0f, lutteur, m_pAnim, false);
	}

	else
	{
		AnimationUtil::animate(s_PathDefeat2, 2, 1.0f, lutteur, m_pAnim, false);

	}

}

void  StateDefeat::Execute(Lutteur* lutteur, Lutteur* other, float dt)
{

	//lutteur->setPositionX(lutteur->getPositionX() + 1);

	//m_fTimeElapsed += dt;


	//if (m_fTimeElapsed >= 0.20f)
		//lutteur->leweto();


	// This is an animation that is not looped
	// so the animation is deleted when it finished
	//if (lutteur->getActionByTag(0) == nullptr)
	//{
	//lutteur->setPositionX(lutteur->getPositionX() + 1);
	//lutteur->leweto();
	//}
}

void  StateDefeat::Exit(Lutteur* lutteur)
{
	// stop the animation

	//if (m_pAnim != nullptr)
	//{
	//lutteur->stopActionByTag(0);

	//}


}
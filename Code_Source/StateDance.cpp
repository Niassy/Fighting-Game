#include "StateDance.h"
#include "Lutteur.h"
#include "Animate.h"
#include "ressouces_file.h"
#include "Type_State.h"

/*

When you enter this state,
the wrestler is in the position
// leweto
*/
void StateDance::Enter(Lutteur* lutteur)
{
	m_itype = type_Dance;

	//lutteur->setScale(0.2f);
	lutteur->setScale(CC_CONTENT_SCALE_FACTOR() * 0.15f);

	//lutteur->setTexture("Block_Gauche/Image.png");

	// check for the orientation of the wrestler
	if (lutteur->getOrientation() == Lutteur::orientation::left)
	{
		AnimationUtil::animate(s_PathDance1, 9, 1.8f, lutteur, m_pRepeat, true);	
	}

	else
	{
		AnimationUtil::animate(s_PathDance2, 9, 1.8f, lutteur, m_pRepeat, true);
	}

}

void StateDance::Execute(Lutteur* lutteur, Lutteur* other, float dt)
{
	//lutteur->setPositionX(lutteur->getPositionX() + 1);
}

void StateDance::Exit(Lutteur* lutteur)
{
	// stop the animation
	//if (m_pRepeat != nullptr)
	if (lutteur->getActionByTag(1))
		lutteur->stopActionByTag(1);

}
#include "StateEtourdi.h"
#include "Lutteur.h"
#include "Animate.h"
#include "ressouces_file.h"
#include "Type_State.h"
#include "GameWorld.h"

USING_NS_CC;

/*

When you enter this state,
the wrestler is in the position
// leweto
*/
void StateEtourdi::Enter(Lutteur* lutteur)
{
	m_itype = type_Etourdi;
	m_fTimeElapsed = 0;


	//lutteur->setScale(0.2f);
	lutteur->setScale(CC_CONTENT_SCALE_FACTOR() * 0.15f);

	//lutteur->setTexture("Block_Gauche/Image.png");

	// check for the orientation of the wrestler
	if (lutteur->getOrientation() == Lutteur::orientation::left)
	{
		//AnimationUtil::animate(s_PathLeweto, 9, 0.9f, lutteur,m_pRepeat, true);
		AnimationUtil::animate(s_PathEtourdiGauche, 3, 0.3f, lutteur, m_pRepeat, true);
	}

	else
	{
		//AnimationUtil::animate(s_PathLeweto1, 9, 0.9f, lutteur, m_pRepeat, true);
		AnimationUtil::animate(s_PathEtourdiDroite, 3, 0.3f, lutteur, m_pRepeat, true);
	}

	////////////////////// fx
	// animate fx
	//lutteur->m_pGame->animateFXEtourdi(cocos2d::Vec2(lutteur->getPosition().x, lutteur->getPosition().y * 1.5f));

}

void StateEtourdi::Execute(Lutteur* lutteur, Lutteur* other, float dt)
{
	m_fTimeElapsed += dt;

	int hp1 = lutteur->loadingBarEnergy;
	int hp2 = other->loadingBarEnergy;

	float dist = lutteur->getPosition().distance(other->getPosition());


	// posseded
	if (lutteur->m_bPosseded == true)
	{

	}


	if (!lutteur->isVeryLowlyHealth())
		lutteur->leweto();
}


void StateEtourdi::Exit(Lutteur* lutteur)
{
	// stop the animation
	//if (m_pRepeat != nullptr)
	if (lutteur->getActionByTag(1))
		lutteur->stopActionByTag(1);

}
#include "StateProjection.h"
#include "Lutteur.h"
#include "Animate.h"
#include "ressouces_file.h"
#include "GameWorld.h"

void StateProjection::Enter(Lutteur* lutteur)
{
	//lutteur->setScale(0.2f);
	//lutteur->setTexture("Block_Gauche/Image.png");


	m_fTimeElapsed = 0;

	m_itype = type_Projection;

	//lutteur->setScale(0.15);
	//lutteur->setScale(CC_CONTENT_SCALE_FACTOR() * 0.15f);

	lutteur->setScale(CC_CONTENT_SCALE_FACTOR() * 0.13f);


	// check for the orientation of the wrestler
	if (lutteur->getOrientation() == Lutteur::orientation::left)
	{
		AnimationUtil::animate(s_PathProjection1, 3, 2.2f, lutteur, m_pAnim, false);
	}

	else
	{
		AnimationUtil::animate(s_PathProjection2, 3, 2.2f, lutteur, m_pAnim, false);

	}

	// check for orientation
	//lutteur->setPositionY(lutteur->getPositionY() + 30);

	//lutteur->setPositionY(lutteur->getPositionY() - 10);
	lutteur->setPositionY(lutteur->getPositionY() - GameWorld::getHeight() / 45.71f );


}

void  StateProjection::Execute(Lutteur* lutteur, Lutteur* other, float dt)
{
	m_fTimeElapsed += dt;

	/*if (m_fTimeElapsed >= 0.1 )
	{
	// need more rigorous test
	if (!other->isDamaged())
	other->setDamaged(true);
	}

	if (other->isDamaged())
	other->takePunch();*/



	// test case when the two wrestler are on
	// the punch state

	if (!other->isInStateBeProjected())
	{
		if (!other->isInStateDefeat())
			other->beProjected();

	}


	// This is an animation that is not looped
	// so the animation is deleted when it finished
	if (lutteur->getActionByTag(0) == nullptr)
	{


		// test for impact

		//if (other->getPosition().distance(lutteur->getPosition()) <= 100)
			//other->takePunch();

		//lutteur->setPositionX(lutteur->getPositionX() + 1);
		//lutteur->dance();



		////////// new ////////
		if (m_fTimeElapsed >= 6.0f)
		{
			lutteur->dance();

			//lutteur->m_pGame->arbiterFinish();
		}
	}
}

void  StateProjection::Exit(Lutteur* lutteur)
{
	// stop the animation

	//if (m_pAnim != nullptr)
	//{
	//lutteur->stopActionByTag(0);

	//}

}
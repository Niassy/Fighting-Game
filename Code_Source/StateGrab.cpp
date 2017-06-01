#include "StateGrab.h"
#include "Lutteur.h"
#include "Animate.h"
#include "ressouces_file.h"
#include "Type_State.h"
//#include "HelloWorldScene.h"
#include "GameWorld.h"

/*

When you enter this state,
the wrestler is in the position
// leweto
*/
void StateGrab::Enter(Lutteur* lutteur)
{
	m_fTimeElapsed = 0.0f;
	lutteur->m_iMaxSmash = 0;
	lutteur->m_iNumberSmash = 0;
	lutteur->m_fTimeBeforeSmash = 0.15f;

	m_vOldPos = lutteur->getPosition();
	m_itype = type_Grab;
	lutteur->m_fTimeBeforeSmash = 0.15f;
	lutteur->m_pGame->setTimeSmash(2.0f);

	//lutteur->setScale(0.2f);
	lutteur->setScale(CC_CONTENT_SCALE_FACTOR() * 0.15f);

	//lutteur->setTexture("Block_Gauche/Image.png");

	// check for the orientation of the wrestler
	if (lutteur->getOrientation() == Lutteur::orientation::left)
	{
		AnimationUtil::animate(s_PathGrab1, 3, 0.6f, lutteur, m_pRepeat, true);
		//lutteur->setPositionX(lutteur->getPositionX() + 10);
		lutteur->setPositionX(lutteur->getPositionX() + GameWorld::getWidth() / 48.0f);

	}

	else
	{
		AnimationUtil::animate(s_PathGrab2, 3, 0.6f, lutteur, m_pRepeat, true);
		//lutteur->setPositionX(lutteur->getPositionX() - 50);
		lutteur->setPositionX(lutteur->getPositionX() - GameWorld::getWidth()/ 9.6f);


		//lutteur->setPositionZ(lutteur->getPositionZ() - 50);
	}

	// lutteur
	//lutteur->setPositionY(lutteur->getPositionY() - 40);

	lutteur->setPositionY(lutteur->getPositionY() - GameWorld::getHeight() / 10.67f);

}

// 1st lethod
void StateGrab::Execute(Lutteur* lutteur, Lutteur* other, float dt)
{
	m_fTimeElapsed += dt;
	//lutteur->setPositionX(lutteur->getPositionX() + 0.1f);

	//lutteur->m_iNumberSmash++;

	// calculate

	if (/*lutteur->m_pGame->getTimeSmash() <= 0*/ m_fTimeElapsed >= 5)
	{
		lutteur->leweto();
		other->leweto();
		// calculate

		// okay finish determine the winner

		// exit the function
		//return;
		int smash1 = lutteur->m_iNumberSmash;
		int smash2 = other->m_iNumberSmash;

		// smash who win
		if (smash1 > smash2 )
		{
			//other->receiveDamage(20);
			other->loadingBarEnergy -= 12;

			/*if (other->loadingBarEnergy <= 0)
			{
				lutteur->project();
				other->beProjected();

			}*/

			if (other->isVeryLowlyHealth())
			{
				other->beEtourdi();
				return;
			}

			else
			{

				lutteur->leweto();
				other->leweto();

			}

		}

		else
		{

			//lutteur->receiveDamage(20);
			lutteur->loadingBarEnergy -= 12;

			/*if (lutteur->loadingBarEnergy <= 0)
			{
				other->project();
				lutteur->beProjected();

			}*/
			if (lutteur->isVeryLowlyHealth())
			{
				lutteur->beEtourdi();
				return;
			}

			else
			{

				lutteur->leweto();
				other->leweto();

			}
		}

		return;
	}

		lutteur->m_fTimeBeforeSmash -= dt;
	
		if (lutteur->m_fTimeBeforeSmash <= 0)
		{
			lutteur->m_iMaxSmash++;
	
			if (lutteur->m_bPosseded == true)
			{
				
				// you can use 
				lutteur->m_iNumberSmash = 20;
			}
	
			else
			{
				if (lutteur->m_pGame->getInputDaan())
				{
					// you can use 
					//lutteur->m_iNumberSmash++;

					//lutteur->setPositionX(lutteur->getPositionX() + 1);
				}
	
				//else
					//lutteur->m_iNumberSmash--;
	
			}
	
			lutteur->m_fTimeBeforeSmash = 0.15f;
	
		}
	


}



// 1st lethod
//void StateGrab::Execute(Lutteur* lutteur, Lutteur* other, float dt)
//{
//	//lutteur->setPositionX(lutteur->getPositionX() + 0.1f);
//
//	//lutteur->m_iNumberSmash++;
//
//
//	// the time for smash is elapsed
//
//	if (lutteur->m_pGame->getTimeSmash() <= 0)
//	{
//	   // calculate
//
//		// okay finish determine the winner
//
//		int smash1 = lutteur->m_iNumberSmash;
//	    int smash2 = other->m_iNumberSmash;
//
//
//		if (smash1 > smash2)
//		{
//			//lutteur->project();
//			//other->beProjected();
//
//			other->receiveDamage(20);
//			other->loadingBarEnergy -= 14;
//
//
//			if (other->loadingBarEnergy <= 0)
//			{
//				lutteur->project();
//				other->beProjected();
//
//			}
//			else
//			{
//
//				lutteur->leweto();
//				other->leweto();
//
//			}
//
//		}
//
//		else
//		{
//			//lutteur->project();
//			//other->beProjected();
//
//			lutteur->receiveDamage(20);
//			lutteur->loadingBarEnergy -= 14;
//
//
//
//			if (lutteur->loadingBarEnergy <= 0)
//			{
//				other->project();
//				lutteur->beProjected();
//
//			}
//			else
//			{
//
//				lutteur->leweto();
//				other->leweto();
//
//			}
//
//		}
//		//
//		
//
//		// exit the function
//		return ;
//	}
//
//	// for the main player
//	// he cannot smash at allk frametimes
//	lutteur->m_fTimeBeforeSmash -= dt;
//
//	if (lutteur->m_fTimeBeforeSmash <= 0)
//	{
//		lutteur->m_iMaxSmash++;
//
//		if (lutteur->m_bPosseded == true)
//		{
//			// you can use 
//			lutteur->m_iNumberSmash++;
//		}
//
//		else
//		{
//			if (lutteur->m_pGame->getInputDaan())
//			{
//				// you can use 
//				lutteur->m_iNumberSmash++;
//			}
//
//			else
//				lutteur->m_iNumberSmash--;
//
//		}
//
//		lutteur->m_fTimeBeforeSmash = 0.15f;
//
//	}
//
//}
//
//void StateGrab::Execute(Lutteur* lutteur, Lutteur* other, float dt)
//{
//	//lutteur->setPositionX(lutteur->getPositionX() + 0.1f);
//
//	//lutteur->m_iNumberSmash++;
//
//
//	// the time for smash is elapsed
//
//	if (lutteur->m_pGame->getTimeSmash() <= 0)
//	{
//		// calculate
//
//		// okay finish determine the winner
//
//		int energy1 = lutteur->CalculateEnergySmash();
//		int energy2 = other->CalculateEnergySmash();
//
//		int hp1 = lutteur->energie;
//		int hp2 = other->energie;
//
//		// bar energy
//
//		int load1 = lutteur->loadingBarEnergy;
//		int load2 = other->loadingBarEnergy;
//
//		// smash energy the loser of smash to be retrived
//		int smashReceived = abs(energy1 - energy2);
//
//
//		// the 1st wrestler wins
//		if (energy1 > energy2)
//		{
//			int diff = energy1 - energy2;
//
//			int health = hp2 - diff;
//
//			other->receiveDamage(smashReceived);
//
//			// loading bar equivalent
//			// 10   -> 7
//			// smash  -> ?
//
//			int smashloa = int(7 * smashReceived / 10);
//			other->loadingBarEnergy -= smashloa;
//
//
//			// the other loses
//			if (hp2 <= 0)
//			{
//				other->beProjected();
//				lutteur->project();
//			}
//
//			else
//			{
//				lutteur->leweto();
//				other->leweto();
//			}
//
//
//		}
//
//		// the second
//		else
//		{
//			int diff = energy2 - energy1;
//
//			int health = hp1 - diff;
//
//			lutteur->receiveDamage(smashReceived);
//
//			int smashloa = int(7 * smashReceived / 10);
//			lutteur->loadingBarEnergy -= smashloa;
//
//
//			if (hp1 <= 0)
//			{
//				lutteur->beProjected();
//				other->project();
//			}
//
//			else
//			{
//				lutteur->leweto();
//				other->leweto();
//
//			}
//		}
//
//		// exit the function
//		return;
//	}
//
//	// for the main player
//	// he cannot smash at allk frametimes
//	lutteur->m_fTimeBeforeSmash -= dt;
//
//	if (lutteur->m_fTimeBeforeSmash <= 0)
//	{
//		lutteur->m_iMaxSmash++;
//
//		if (lutteur->m_bPosseded == false)
//		{
//			// you can use 
//			lutteur->m_iNumberSmash++;
//		}
//
//		else
//		{
//			if (lutteur->m_pGame->getInputDaan())
//			{
//				// you can use 
//				lutteur->m_iNumberSmash++;
//			}
//
//			else
//				lutteur->m_iNumberSmash--;
//
//		}
//
//		lutteur->m_fTimeBeforeSmash = 0.15f;
//
//	}
//
//}

void StateGrab::Exit(Lutteur* lutteur)
{
	lutteur->setPosition(m_vOldPos);

	// stop the animation
	//if (m_pRepeat != nullptr)
	if (lutteur->getActionByTag(1))
		lutteur->stopActionByTag(1);


}
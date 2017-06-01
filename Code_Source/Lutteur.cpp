#include "Lutteur.h"
#include "StateLeweto.h"
#include "StateMoveForWard.h"
#include "StatePunch.h"
#include "StateUppercut.h"
#include "StateTakePunch.h"
#include "StateTakeUppercut.h"
#include "StateProjection.h"
#include "StateBeProjected.h"
#include "StateGrab.h"
#include "StateDefeat.h"
#include "StateDance.h"
#include "Type_State.h"
#include "StateMoveDownWard.h"
#include "StateEtourdi.h"
#include "StateBlock.h"
#include "StatePunch.h"
#include "StatePunchRoffo.h"
#include "StateTakePunchRoffo.h"
//#include "HelloWorldScene.h"
#include "GameWorld.h"

USING_NS_CC;

Lutteur* Lutteur::create()
{
	Lutteur *sprite = new (std::nothrow) Lutteur();
	if (sprite && sprite->init())
	{
		sprite->autorelease();

		return sprite;
	}

	CC_SAFE_DELETE(sprite);
	return nullptr;

}

/*---------------Start--------------

This function must be called after the wrestler is created
It initalises all necessary component of the wrestler
*/
void Lutteur::Start()
{
	m_pStateMachine = new StateMachine<Lutteur>(this);

	m_pStateMachine->SetCurrentState(new StateLeweto());

	m_pStateMachine->CurrentState()->Enter(this);

	// the wrestler is not damaged
	m_bDamaged = false;

	// not controlled by ai by default
	m_bPosseded = false;


	// power of the wrestler
	puissance = 75;

	// energy of the wrestler
	energie = 100;

	m_dRateRegen = 1;


	// at first
	loadingBarEnergy = 85;


	maxLoadingBarEnergy = 85;


	// number of smash
	m_iNumberSmash = 0;

	m_iMaxSmash = 0;

	m_fTimeBeforeSmash = 0.15f;

	// rate punch
	m_dRatePunch = 0.5f;
	m_fNextTimePunch = 0;
}



//void Lutteur::animateLewto()
//{
//	//
//	// Manual animation
//	//
//	auto animation = Animation::create();
//	for (int i = 1; i<10; i++)
//	{
//		char szName[100] = { 0 };
//		sprintf(szName, "Png/Image.%03d.png", i);
//		animation->addSpriteFrameWithFile(szName);
//	}
//
//
//	// should last 2.8 seconds. And there are 14 frames.
//	animation->setDelayPerUnit(1.8f / 9.0f);
//	animation->setRestoreOriginalFrame(false);
//
//	auto action = Animate::create(animation);
//
//	auto repeat = RepeatForever::create(action);
//
//	m_pActionLewto = repeat;
//	
//	runAction( repeat);
//
//	setScale(0.2);
//
//}
//
//
//
//// not a good function
//// delete it after
//
//void Lutteur::animateLewtoDroite()
//{
//	//
//	// Manual animation
//	//
//	auto animation = Animation::create();
//	for (int i = 1; i<10; i++)
//	{
//		char szName[100] = { 0 };
//		sprintf(szName, "Droite/Image.%03d.png", i);
//		animation->addSpriteFrameWithFile(szName);
//	}
//
//
//	// should last 2.8 seconds. And there are 14 frames.
//	animation->setDelayPerUnit(1.8f / 9.0f);
//	animation->setRestoreOriginalFrame(false);
//
//	auto action = Animate::create(animation);
//	auto reverse = action->reverse();
//
//	runAction(RepeatForever::create(action));
//
//	setScale(0.2);
//	//setRotation(45);
//
//}
//
//
//void Lutteur::animatePunch()
//{
//	auto animation = Animation::create();
//	for (int i = 1; i<8; i++)
//	{
//		char szName[100] = { 0 };
//		sprintf(szName, "Punch_Gauche/Image.%03d.png", i);
//		animation->addSpriteFrameWithFile(szName);
//	}
//
//
//	// should last 2.8 seconds. And there are 14 frames.
//	animation->setDelayPerUnit(0.7f / 7.0f);
//	animation->setRestoreOriginalFrame(true);
//
//
//	if (m_pActionLewto)
//		stopAction(m_pActionLewto);
//
//	auto action = Animate::create(animation);
//
//	runAction(action);
//
//	m_pActionPunch = action;
//
//
//	//setScale(0.2);
//
//}
//
//void Lutteur::animateUppercut()
//{
//	auto animation = Animation::create();
//	for (int i = 1; i<10; i++)
//	{
//		char szName[100] = { 0 };
//		sprintf(szName, "Uppercut_Gauche/Image.%03d.png", i);
//		animation->addSpriteFrameWithFile(szName);
//	}
//
//	// should last 2.8 seconds. And there are 14 frames.
//	animation->setDelayPerUnit(1.4f / 9.0f);
//	animation->setRestoreOriginalFrame(true);
//
//	if (m_pActionLewto)
//		stopAction(m_pActionLewto);
//
//	auto action = Animate::create(animation);
//
//	runAction(action);
//
//	//m_pActionPunch = action;
//
//}
//
//void Lutteur::animateBlock()
//{
//	setTexture("Block_Gauche/Image.png");
//}
//
//
//void Lutteur::animateTakingDmgDirect()
//{
//	setTexture("TakingDmgDirect_Gauche/Image.png");
//}


/*----------------Update-----------

*/
void Lutteur::update(float dt, Lutteur* other)
{
	// update the wrestler
	// using finiteStateMachine
	m_pStateMachine->Update(dt,other);

	if (isInStateLeweto() || isInStatePunch() || isInStateUppercut() || isInStateEtourdi() )
		updateTimeReloadEnergy(dt);

}

void Lutteur::animate(char* file, int nbFrames, float delay, cocos2d::Sprite* sprite, bool repeat)
{

}


void Lutteur::leweto()
{
	m_pStateMachine->ChangeState(new StateLeweto());
}


// use the position
void Lutteur::moveForward()
{
	m_pStateMachine->ChangeState(new StateMoveForward(getPosition()));
}

void Lutteur::moveForward(float distance)
{
	m_pStateMachine->ChangeState(new StateMoveForward(distance));
}

void Lutteur::moveDownWard()
{
	m_pStateMachine->ChangeState(new StateMoveDownWard(getPosition()));

}

void Lutteur::moveDownWard(float distance)
{
	m_pStateMachine->ChangeState(new StateMoveDownWard(distance));
}

void Lutteur::punch()
{
	// make a punch
	m_pStateMachine->ChangeState(new StatePunch());
}

void Lutteur::punchRoffo()
{
	// make a punch
	m_pStateMachine->ChangeState(new StatePunchRoffo());

}


void Lutteur::upperCut()
{
	// make a punch
	m_pStateMachine->ChangeState(new StateUppercut());

}

void Lutteur::takePunch()
{
	// take a punch
	m_pStateMachine->ChangeState(new StateTakePunch());
}

void Lutteur::takePunchRoffo()
{
	// take a punch
	m_pStateMachine->ChangeState(new StateTakePunchRoffo());
}

void Lutteur::takeUpperCut()
{
	// take a uppercut
	m_pStateMachine->ChangeState(new StateTakeUppercut());
}

void Lutteur::block()
{
	m_pStateMachine->ChangeState(new StateBlock());
}

void Lutteur::grab()
{
	m_pStateMachine->ChangeState(new StateGrab());
}

void Lutteur::project()
{
	m_pStateMachine->ChangeState(new StateProjection());
}

void Lutteur::beProjected()
{
	m_pStateMachine->ChangeState(new StateBeProjection());
}




void Lutteur::dance()
{
	m_pStateMachine->ChangeState(new StateDance());
}

void Lutteur::beDefeated()
{
	m_pStateMachine->ChangeState(new StateDefeat());
}

void Lutteur::beEtourdi()
{
	m_pStateMachine->ChangeState(new StateEtourdi());
}



// set the orientation to the left
void Lutteur::setOrientationLeft()
{
	m_pOrientation = orientation::left;
}

// set the orientation to the right
void Lutteur::setOrientationRight()
{
	m_pOrientation = orientation::right;
}


// true when the wrestler is doing "leweto"
bool Lutteur::isInStateLeweto()
{
	return m_pStateMachine->CurrentState()->getType() == type_Leweto;
}

bool Lutteur::isInStatePunch()
{
	return m_pStateMachine->CurrentState()->getType() == type_Punch;
}

bool Lutteur::isInStateUppercut()
{
	return m_pStateMachine->CurrentState()->getType() == type_Uppercut;

}


bool Lutteur::isInStateGrab()
{
	return m_pStateMachine->CurrentState()->getType() == type_Grab;
}


bool Lutteur::isInStateProjection()
{
	return m_pStateMachine->CurrentState()->getType() == type_Projection;
}

bool Lutteur::isInStateBeProjected()
{
	return m_pStateMachine->CurrentState()->getType() == type_BeProjected;
}


bool Lutteur::isInStateBlock()
{
	return m_pStateMachine->CurrentState()->getType() == type_Block;
}



bool Lutteur::isInStateDefeat()
{
	return m_pStateMachine->CurrentState()->getType() == type_Defeat;
}

bool Lutteur::isInStateDance()
{
	return m_pStateMachine->CurrentState()->getType() == type_Dance;
}

bool Lutteur::isInStateEtourdi()
{
	return m_pStateMachine->CurrentState()->getType() == type_Etourdi;
}

bool Lutteur::isInStateMoveForWard()
{
	return m_pStateMachine->CurrentState()->getType() == type_MoveForward;
}

bool Lutteur::isInStateMoveDownWard()
{
	return m_pStateMachine->CurrentState()->getType() == type_MoveDownward;

}


bool Lutteur::isInStatePunchRoffo()
{
	return m_pStateMachine->CurrentState()->getType() == type_PunchRoffo;
}

bool Lutteur::isInStateTakePunchRoffo()
{
	return m_pStateMachine->CurrentState()->getType() == type_TakePunchRoffo;

}




//returns true if the current state's type is equal to the type of the
//class passed as a parameter. 
/*bool Lutteur:: isInStateLeweto(const State<Lutteur>& st)const
{
	return m_pStateMachine->isInState(new StateLeweto() ) == true;
}*/

// damage
void Lutteur::receiveDamage(float dmg)
{
	energie -= dmg;

	if (energie <= 0)
		energie = 0;

}

// reload energy
void Lutteur::reloadEnergy()
{
	energie += 1;
	loadingBarEnergy += 1;

	if (energie >= 100)
		energie = 100;

	if (loadingBarEnergy > 85)
		loadingBarEnergy = 85;

}


// update reload energy time
void Lutteur::updateTimeReloadEnergy(float dt)
{
	m_dRateRegen -= dt;

	if (m_dRateRegen <= 0)
	{
		m_dRateRegen = 1;
		reloadEnergy();
	}

}


bool Lutteur::isReadyForPunch( )
{ 
	return m_pGame->getElapsedTime() >= m_fNextTimePunch;
}


void Lutteur::updateTimePunch()
{
	m_fNextTimePunch = m_pGame->getElapsedTime() + 1.0f / m_dRatePunch;
}

// this function return true when the wrestler
// want to flee
bool Lutteur::needToFlee(Lutteur* other)
{

	// do not move forward if collide
	// with lzfdt screen

	//if (collideWithRightScreen())
		//return false;


	int hp1 = loadingBarEnergy;
	int hp2 = other->loadingBarEnergy;

	float dist = getPosition().distance(other->getPosition());

	return (needToMoveForwardPunch(other) == false || needToMoveForwardGrab(other) == false || needToPunch(other) == false);
}


// this function return true when the wrestler
// need to mobe forward
bool Lutteur::needToMoveForwardPunch(Lutteur* other)
{

	// do not move if collide


	int hp1 = loadingBarEnergy;
	int hp2 = other->loadingBarEnergy;


	float dist = getPosition().distance(other->getPosition());

	if (getDistanceFromPunch(other))
		return false;

	if (this->isFullyHealth())
		return true;

	if (isMediumlyHealth())
		return true;


	if (isLowLyHealthly())
	{
		if (hp2 > hp1)
		{
			if (hp2 - hp1 <= 5)
				return true;
		}
	}


	return false;
}


// this function return true when the wrestler
// need to move forward
bool Lutteur::needToMoveForwardGrab(Lutteur* other)
{
	int hp1 = loadingBarEnergy;
	int hp2 = other->loadingBarEnergy;

	float dist = getPosition().distance(other->getPosition());

	if (getDistanceFromGrab(other))
	{
		return false;
	}

	if (isFullyHealth())
		return true;

	if (isMediumlyHealth())
		return true;

	if (isLowLyHealthly())
	{
		if (hp1 > hp2)
			return true;

		else
		{
			int diff = hp2 - hp1;

			if (diff <= 5)
				return true;
		}

		//return true;

		//return false;
	}

	if (isVeryLowlyHealth())
	{
		if (hp1 > hp2)
			return true;

		else
		{
			int diff = hp2 - hp1;

			if (diff <= 5)
				return true;
		}

		//return false;
	}


	return false;
}



// this function return true when the wrestler
// need to punch
bool Lutteur::needToPunch(Lutteur* other)
{

	int hp1 = loadingBarEnergy;
	int hp2 = other->loadingBarEnergy;

	float dist = getPosition().distance(other->getPosition());


	if (!getDistanceFromPunch(other))
	{
		return false;
	}

	// making grab
	if (other->isVeryLowlyHealth() || other->isLowLyHealthly() || other->isMediumlyHealth())
		return false;


	if (isFullyHealth())
		return true;

	if (isMediumlyHealth())
		return true;

	//if (isLowLyHealthly())
	//{
	//	if (hp1 > hp2)
	//		return true;

	//	else
	//	{

	//		int diff = hp2 - hp1;

	//		if (diff <= 10)
	//			return true;
	//	}

	//	//return false;
	//}


	//if (isVeryLowlyHealth())
	//{
	//	if (hp1 > hp2)
	//		return true;

	//	else
	//	{
	//		int diff = hp2 - hp1;

	//		if (diff <= 5)
	//			return true;
	//	}
	//}
	return false;
}


// this function returns true when the wreslter
// need to grab
bool Lutteur::needToGrab(Lutteur* other)
{
	int hp1 = loadingBarEnergy;
	int hp2 = other->loadingBarEnergy;

	float dist = getPosition().distance(other->getPosition());


	if (!getDistanceFromGrab(other)  /*&& hp2 < 10*/)
	{
		return false;
	}

	if (isFullyHealth())
		return true;

	if (isMediumlyHealth())
		return true;

	if (isLowLyHealthly())
		return true;

	if (isVeryLowlyHealth())
	{
		if (hp1 > hp2)
			return true;

		else
		{
			int diff = hp2 - hp1;

			if (diff <= 5)
				return false;
		}
	}

	
	return false;
}


bool Lutteur::getDistanceFromPunch(Lutteur* other)
{
	int hp1 = loadingBarEnergy;
	int hp2 = other->loadingBarEnergy;

	float dist = getPosition().distance(other->getPosition());

	//if (dist <= 80 /*&& dist > 70*/)
		//return true;

	if (dist <= Lutteur::getDistanceFromPunch())
		return true;

	return false;
}

bool Lutteur::getDistanceFromUppercut(Lutteur* other)
{
	float dist = getPosition().distance(other->getPosition());

	//if (dist <= 80 /*&& dist > 70*/)
	//return true;

	if (dist <= Lutteur::getDistanceFromUppercut())
		return true;

	return false;

}


bool Lutteur::getDistanceFromGrab(Lutteur* other)
{

	int hp1 = loadingBarEnergy;
	int hp2 = other->loadingBarEnergy;

	float dist = getPosition().distance(other->getPosition());

	/*if (dist <= 70)
		return true;*/

	if (dist <= Lutteur::getDistanceFromGrab())
		return true;


	return false;
}

// true if wrestler need to block
bool Lutteur::needToBlock(Lutteur* other)
{
	if (collideWithLeftScreen())
	{
		if (isLowLyHealthly())
			return true;
	}
}

bool Lutteur::isFullyHealth()
{
	if (loadingBarEnergy <= 85 && loadingBarEnergy >= 60)
		return true;

	return false;
}

bool Lutteur::isMediumlyHealth()
{
	if (loadingBarEnergy <60 && loadingBarEnergy >= 35)
		return true;

	return false;
}

bool Lutteur::isLowLyHealthly()
{
	if (loadingBarEnergy <35 && loadingBarEnergy >= 25)
		return true;

	return false;
}

bool Lutteur::isVeryLowlyHealth()
{
	if (loadingBarEnergy < 25 )
		return true;

	return false;
}


// now distance = 60
float Lutteur::getDistanceFromPunch()
{
	//return 80.0f;
	//return GameWorld::getWidth() / 6;
	return GameWorld::getWidth() / 8;

}

// now distance = 60
float Lutteur::getDistanceFromUppercut()
{
	//return 80.0f;
	//return GameWorld::getWidth() / 6;
	return GameWorld::getWidth() / 8.5f;

}

// now distance = 50
float Lutteur::getDistanceFromGrab()
{
	//return 70.0f;

	//return GameWorld::getWidth() / 6.85;

	return GameWorld::getWidth() / 9.6f;

}


float Lutteur::getDistanceFlee()
{
	//return 130.0f;

	return GameWorld::getWidth() / 3.69f;

}

bool Lutteur::isFromDistanceFlee(Lutteur* other)
{
	float dist = getPosition().distance(other->getPosition());

	if (dist >= Lutteur::getDistanceFlee())
		return true;

	return false;
}

bool Lutteur::collide(Lutteur* other)
{
	float dist = getPosition().distance(other->getPosition());

	if (dist < Lutteur::getDistanceFromGrab())
		return true;

	return false;
}

bool Lutteur::collideWithLeftScreen()
{
	float length = getPosition().x;

	float size = this->getContentSize().width * 0.15f;

	/*if (length - 70 <= 0)
		return true;*/

	if (length  -  size  <= 0)
		return true;

	return false;
}

bool Lutteur::collideWithRightScreen()
{
	float length = getPosition().x;

	float size = this->getContentSize().width;

	if (length /*+ size*/ >= /*HelloWorld::getWidth()*/GameWorld::getWidth() * 0.8f )
		return true;

	return false;


}


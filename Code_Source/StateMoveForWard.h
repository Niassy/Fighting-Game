#ifndef _STATE_MOVEFORWARD_

#define _STATE_MOVEFORWARD_

#include "State.h"


#include "cocos2d.h"

class Lutteur;

class StateMoveForward : public State<Lutteur>
{


private:


	// timer for draw fx
	float m_fTimerFX;

protected:




public:

	// this is the distance that separate other
	// and the owner of his state when walking
	// typically used by AI
	float m_fDistanceFromOpponent;

	// the old position of the wreslter
	cocos2d::Vec2 m_vOldPos;


	StateMoveForward(){}


	StateMoveForward(float dist){ m_fDistanceFromOpponent = dist; }


	// use this contructor for player wrestler
	StateMoveForward(cocos2d::Vec2 oldPos){ m_vOldPos = oldPos; }


	virtual void Enter(Lutteur* lutteur);

	virtual void Execute(Lutteur* lutteur, Lutteur* other, float dt);

	virtual void Exit(Lutteur* lutteur);


};


#endif
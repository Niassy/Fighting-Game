#ifndef _STATE_MOVEDOWNWARD_

#define _STATE_MOVEDOWNARD_

#include "State.h"

#include "cocos2d.h"

class Lutteur;

class StateMoveDownWard : public State<Lutteur>
{


private:


protected:

	// this is the distance that separate other
	// and the owner of his state when walking
	float m_fDistanceFromOpponent;

	// the old position of the wreslter
	cocos2d::Vec2 m_vOldPos;

	// timer for draw fx
	float m_fTimerFX;


public:

	StateMoveDownWard(){}

	StateMoveDownWard(float dist){ m_fDistanceFromOpponent = dist; }

	// use this contructor for player wrestler
	StateMoveDownWard(cocos2d::Vec2 oldPos){ m_vOldPos = oldPos; }


	virtual void Enter(Lutteur* lutteur);

	virtual void Execute(Lutteur* lutteur, Lutteur* other, float dt);

	virtual void Exit(Lutteur* lutteur);


};


#endif
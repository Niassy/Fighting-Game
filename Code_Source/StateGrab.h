#ifndef _STATE_GRAB_

#define _STATE_GRAB_

#include "State.h"

#include "cocos2d.h"


class Lutteur;


class StateGrab : public State<Lutteur>
{


private:


protected:


	cocos2d::Vec2 m_vOldPos;
public:

	StateGrab(){}


	virtual void Enter(Lutteur* lutteur);

	virtual void Execute(Lutteur* lutteur, Lutteur* other, float dt);

	virtual void Exit(Lutteur* lutteur);


};


#endif
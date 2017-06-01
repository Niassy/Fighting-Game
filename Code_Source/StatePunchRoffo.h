#ifndef _STATE_PUNCHROFFO_

#define _STATE_PUNCHROFFO_

#include "State.h"

class Lutteur;

class StatePunchRoffo : public State<Lutteur>
{


private:


protected:

	cocos2d::Vec2 m_vOldPos;

public:

	StatePunchRoffo(){}


	virtual void Enter(Lutteur* lutteur);

	virtual void Execute(Lutteur* lutteur, Lutteur* other, float dt);

	virtual void Exit(Lutteur* lutteur);


};


#endif
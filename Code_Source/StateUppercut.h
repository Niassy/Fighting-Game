#ifndef _STATE_UPPERCUT_

#define _STATE_UPPERCUT_

#include "State.h"

class Lutteur;

class StateUppercut : public State<Lutteur>
{


private:


protected:


public:

	StateUppercut(){}

	virtual void Enter(Lutteur* lutteur);

	virtual void Execute(Lutteur* lutteur, Lutteur* other, float dt);

	virtual void Exit(Lutteur* lutteur);

};


#endif
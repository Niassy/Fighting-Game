#ifndef _STATE_DEFEAT_

#define _STATE_DEFEAT_

#include "State.h"

class Lutteur;

class StateDefeat : public State<Lutteur>
{

private:


protected:


public:

	StateDefeat(){}


	virtual void Enter(Lutteur* lutteur);

	virtual void Execute(Lutteur* lutteur, Lutteur* other, float dt);

	virtual void Exit(Lutteur* lutteur);


};


#endif
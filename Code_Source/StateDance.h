#ifndef _STATE_DANCE_

#define _STATE_DANCE_

#include "State.h"

class Lutteur;

class StateDance : public State<Lutteur>
{

private:

protected:


public:

	StateDance(){}


	virtual void Enter(Lutteur* lutteur);

	virtual void Execute(Lutteur* lutteur, Lutteur* other, float dt);

	virtual void Exit(Lutteur* lutteur);


};


#endif
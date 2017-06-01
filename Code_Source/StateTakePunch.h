#ifndef _STATE_TAKEPUNCH_

#define _STATE_TAKEPUNCH_

#include "State.h"

class Lutteur;

class StateTakePunch : public State<Lutteur>
{


private:


protected:


public:

	StateTakePunch(){}


	virtual void Enter(Lutteur* lutteur);

	virtual void Execute(Lutteur* lutteur, Lutteur* other, float dt);

	virtual void Exit(Lutteur* lutteur);


};


#endif
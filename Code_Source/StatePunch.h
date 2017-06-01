#ifndef _STATE_PUNCH_

#define _STATE_PUNCH_

#include "State.h"

class Lutteur;

class StatePunch : public State<Lutteur>
{


private:


protected:


public:

	StatePunch(){}


	virtual void Enter(Lutteur* lutteur);

	virtual void Execute(Lutteur* lutteur, Lutteur* other, float dt);

	virtual void Exit(Lutteur* lutteur);


};


#endif
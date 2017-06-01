#ifndef _STATE_PROJECTION_

#define _STATE_PROJECTION_

#include "State.h"

class Lutteur;

class StateProjection : public State<Lutteur>
{


private:


protected:


public:

	StateProjection(){}


	virtual void Enter(Lutteur* lutteur);

	virtual void Execute(Lutteur* lutteur, Lutteur* other, float dt);

	virtual void Exit(Lutteur* lutteur);


};


#endif
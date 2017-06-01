#ifndef _STATE_BEPROJECTION_

#define _STATE_BEPROJECTION_

#include "State.h"

class Lutteur;

class StateBeProjection : public State<Lutteur>
{


private:


protected:


public:

	StateBeProjection(){}


	virtual void Enter(Lutteur* lutteur);

	virtual void Execute(Lutteur* lutteur, Lutteur* other, float dt);

	virtual void Exit(Lutteur* lutteur);


};


#endif
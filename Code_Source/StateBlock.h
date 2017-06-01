#ifndef _STATE_BLOCK_

#define _STATE_BLOCK_

#include "State.h"

class Lutteur;

class StateBlock : public State<Lutteur>
{


private:


protected:


public:

	StateBlock(){}


	virtual void Enter(Lutteur* lutteur);

	virtual void Execute(Lutteur* lutteur, Lutteur* other, float dt);

	virtual void Exit(Lutteur* lutteur);


};


#endif
#ifndef _STATE_LEWETO_

#define _STATE_LEWETO_

#include "State.h"

class Lutteur;

class StateLeweto: public State<Lutteur>
{


private:


protected:


public:

	StateLeweto(){}


	virtual void Enter(Lutteur* lutteur);

	virtual void Execute(Lutteur* lutteur, Lutteur* other, float dt);

	virtual void Exit(Lutteur* lutteur);


};


#endif
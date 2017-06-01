#ifndef _STATE_ETOURDI_

#define _STATE_ETOURDI_

#include "State.h"

class Lutteur;

class StateEtourdi : public State<Lutteur>
{


private:


protected:


public:

	StateEtourdi(){}


	virtual void Enter(Lutteur* lutteur);

	virtual void Execute(Lutteur* lutteur, Lutteur* other, float dt);

	virtual void Exit(Lutteur* lutteur);


};


#endif
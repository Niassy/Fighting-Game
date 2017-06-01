#ifndef _STATE_TAKEUPPERCUT_

#define _STATE_TAKEUPPERCUT_

#include "State.h"

class Lutteur;

class StateTakeUppercut : public State<Lutteur>
{


private:


protected:


public:

	StateTakeUppercut(){}


	virtual void Enter(Lutteur* lutteur);

	virtual void Execute(Lutteur* lutteur, Lutteur* other, float dt);

	virtual void Exit(Lutteur* lutteur);


};


#endif
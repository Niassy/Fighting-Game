#ifndef STATE_H
#define STATE_H
//------------------------------------------------------------------------
//
//  Name:   State.h
//
//  Desc:   abstract base class to define an interface for a state
//
//  Author:Mamadou Niassy
//
// nb: this class is inspired from the "State" class defined by Matt BuckLand
//
//------------------------------------------------------------------------

#include <string>

#include "cocos2d.h"

#include "Type_State.h"

template <class entity_type>
class State 
{

protected:

	int m_itype;

	// the system of messaging in not perfect
	// so i introduce thois variable to reavtivate
	// a ship that is idel
	//float m_fTimeEnter;


	// time elapsed
	float m_fTimeElapsed;


	// used for animation
	// these are exclusive animation
	// can not play the two on same time

	// repeat animation
	cocos2d::RepeatForever* m_pRepeat;

	// one loop animation
	cocos2d::Animate* m_pAnim;


public:

	virtual ~State(){}

	//this will execute when the state is entered
	virtual void Enter(entity_type*) = 0;

	//this is the states normal update function
	virtual void Execute(entity_type*, entity_type*, float dt) = 0;

	//this will execute when the state is exited. (My word, isn't
	//life full of surprises... ;o))
	virtual void Exit(entity_type*) = 0;

	//void setTimeEnter(float t){ m_fTimeEnter = t; }
	//int getTimeEnter(){ return m_fTimeEnter; }

	std::string getName()const
	{

	/*	if (m_itype == type_Wait_For_An_Tower)
			return "WaitForAnTower";

		else if (m_itype == type_Seek_To_Position)
			return "SeekToPosition";

		else if (m_itype == type_Attack_Target)
			return "AttackTarget";


		else if (m_itype == type_Seek_Along_Pos)
			return "Seek Along Pos";

	*/	return "Nothing";
	}

	const char* getName()
	{

		/*if (m_itype == type_Wait_For_An_Tower)
			return "WaitForAnTower";


		else if (m_itype == type_Seek_To_Position)
			return "SeekToPosition";

		else if (m_itype == type_Attack_Target)
			return "AttackTarget";


		else if (m_itype == type_Seek_Along_Pos)
			return "Seek Along Pos";*/

		return "Nothing";
	}

	// repeat animation
	cocos2d::RepeatForever* getRepeatAnimation(){ return  m_pRepeat; }

	// one loop animation
	cocos2d::Animate* getOneLoopAnimation(){ return m_pAnim; }

	int getType(){ return m_itype; }

	float getElapsedTime(){ return m_fTimeElapsed; }



};

#endif
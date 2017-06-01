

#ifndef _LUTTEUR_


#define _LUTTEUR_


#include "cocos2d.h"
#include "StateMachine.h"
//class HelloWorld;

class GameWorld;

class Lutteur : public cocos2d::Sprite
{

public:

	// position of wrestler
	enum orientation
	{
		left = 0, right
	};

public:
	

	// reference to world
	//HelloWorld* m_pGame;

	GameWorld * m_pGame;

	// power of the wrestler
	int puissance;

	// energy of the wresler
	int energie;

	// energy for loading bar
	int loadingBarEnergy;

	//max loading bar
	int maxLoadingBarEnergy;

	// defense of the wrestler
	int defense;

	// rate of punch
	float m_dRatePunch;

	// next time punch
	float m_fNextTimePunch;

	// rate of uppercut
	float m_dRateUppercut;

	// rate of regeneration power
	float m_dRateRegen;

	// left or right
	orientation m_pOrientation;

	// true when the wrestler is damaged
	bool m_bDamaged;


	// is the wrestle controled by ia
	bool m_bPosseded;

	//an instance of the state machine class
	StateMachine<Lutteur>*  m_pStateMachine;

	// number of smashes
	int m_iNumberSmash;

	// the max splashes
	int m_iMaxSmash;

	// the splash opower
	float m_fSMashPower;

	// time before smash
	float m_fTimeBeforeSmash;



	// uncomment because new architecture of the game
	// animation lewe
	//cocos2d::RepeatForever* m_pActionLewto;

	// animation punch
	//cocos2d::Animate* m_pActionPunch;

public :

	static 	float getDistanceFromPunch();

	static 	float getDistanceFromUppercut();


	static float getDistanceFromGrab();

	static float getDistanceFlee();



	static Lutteur* create();


	void Start();


	/*void animateLewto();
	void animateLewtoDroite();

	void animatePunch();
	void animateUppercut();


	void animateBlock();
	void animateTakingDmgDirect();*/


	// new architecture

	void update(float dt, Lutteur* other);

	void animate(char* file, int nbFrames, float delay, cocos2d::Sprite* sprite, bool repeat = false);

	void leweto();

	void moveForward();

	void moveForward(float distance);


	//void moveForward(Vec3 distance);


	void moveDownWard();

	void moveDownWard(float distance);

	void punch();

	void punchRoffo();


	void upperCut();

	void takePunch();

	void takePunchRoffo();


	void takeUpperCut();

	void block();

	void grab();

	void project();

	void beProjected();

	void dance();

	void beDefeated();

	void beEtourdi();


	// return the state machine
	StateMachine<Lutteur>*  GetFSM()const{ return m_pStateMachine; }


	orientation getOrientation(){ return m_pOrientation; }

	// set the orientation to the left
	void setOrientationLeft();

	// set the orientation to the right
	void setOrientationRight();

	// is the wrestler orientedLeft
	bool isOrientedLeft(){ return m_pOrientation == orientation::left; }

	bool isDamaged(){ return m_bDamaged == true; }

	void setDamaged(bool b){ m_bDamaged = b; }
	bool getDamaged(){ return m_bDamaged; }


	bool isPosseded(){ return m_bPosseded == true; }

	void setPosseded(bool b){ m_bPosseded = b; }
	bool getPosseded(){ return m_bPosseded; }

	float getPower(){ return puissance; }

	void setEnergy(float ene){ energie = ene; }
	float getEnergy(){ return energie; }

	// State Status

	bool isInStateLeweto();
	bool isInStatePunch();
	bool isInStateUppercut();

	bool isInStatePunchRoffo();
	bool isInStateTakePunchRoffo();


	//bool isInStateLeweto();
	bool isInStateGrab();
	bool isInStateEtourdi();


	bool isInStateProjection();
	bool isInStateBeProjected();

	bool isInStateBlock();

	bool isInStateDefeat();
	bool isInStateDance();


	bool isInStateMoveForWard();

	bool isInStateMoveDownWard();

	// time of current state
	float getCurrentStateElapsedTime(){ return m_pStateMachine->CurrentState()->getElapsedTime(); }


	// damage
	void receiveDamage(float dmg);

	// reload energy
	void reloadEnergy();

	// update reload energy time
	void updateTimeReloadEnergy(float dt);


	// state 

	//returns true if the current state's type is equal to the type of the
	//class passed as a parameter. 
	//bool  isInStateLeweto(const State<Lutteur>& st)const;

	int CalculateEnergySmash()
	{
		// for example for the main player
		// energy = 100
		// max smash to determinate  (max)
		// smash we have (smash)
		

		// each frametime suppose the player input
		// button of "smash" with a decalage of 0.3f
		//  we will have our max splash the player is regulary
		// in his output
		// otherwise the splash is not set to max

		// now use the output smash and use this formula
		// if max -> 100 ENERGY 
		// output -> energy to retrieve?

		// energy =  100 * output / max ;

		// after calculayte the diff beetween his output and the opponent
		// the wrestler whose has best output use the difference beetween output
		// and retrieves from opponent energy
		// Easy



		//timeOutputDaan -= dt;
		// functions needed
		// if (timeOutputDaan <= 0)
		/*{

		     maxSplash++;

			if (getinput("daan"))
			  m_isplash++;
			  
			  else
			    m_isplash--;

				if (m_isplash <=0)
				    m_spladh = 0;


			timeOutputDaan = TIME_OUTPUT_DOWN;
		}
		
		// calculate the max
		energy To retrieve = 100 * m_iSplash / max ; 
		
		*/

		if (m_iMaxSmash == 0)
			return 0;

		int energy =  (int )  ( 100 * m_iNumberSmash / m_iMaxSmash );

		return energy;
	}

	bool isReadyForPunch();
	void updateTimePunch();

	// useful fonctiopn for ai logic


	// this function return true when the wrestler
	// want to flee
	bool needToFlee(Lutteur* other);


	// this function return true when the wrestler
	// need to mobe forward
	bool needToMoveForwardPunch(Lutteur* other);

	// this function return true when the wrestler
	// need to mobe forward
	bool needToMoveForwardGrab(Lutteur* other);



	// this function return true when the wrestler
	// need to punch
	bool needToPunch(Lutteur* other);


	// this function returns true when the wreslter
	// need to grab
	bool needToGrab(Lutteur* other);

	// true if wrestler need to block
	bool needToBlock(Lutteur* other);



	bool getDistanceFromPunch(Lutteur* other);

	bool getDistanceFromUppercut(Lutteur* other);

	bool getDistanceFromGrab(Lutteur* other);

	bool isFromDistanceFlee(Lutteur* other);

	bool collide(Lutteur* other);

	bool collideWithLeftScreen();

	bool collideWithRightScreen();


	bool isFullyHealth();

	bool isMediumlyHealth();

	bool isLowLyHealthly();

	bool isVeryLowlyHealth();


};

#endif
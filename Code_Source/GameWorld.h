#ifndef __GAMEWORLD_SCENE_H__
#define __GAMEWORLD_SCENE_H__

#include "cocos2d.h"

class Lutteur;


class GameWorld : public cocos2d::Layer
{

private:

	// time to xwait for starting

	float m_fTimeForStaring;

	// a pointer to the main pointer
	Lutteur* m_pMainLutteur;

	// a pointer to the ia
	Lutteur* m_pIALuttueur;

	// timeremaining before activating input for punch
	float m_fTimeRemainPunch;

	// timeremaining before activating punch for AI
	float m_fTimeRemainPunchIA;

	// true if punch putton is pressed
	bool m_bPunchPressed;

	// count the number of time the ai punches
	int m_iNumberPunch;

	// true if the input daan is pressed
	bool m_bInputSmash;

	// true if the input daan is pressed
	bool m_bInputDaan;

	// mouse click
	bool m_bMouseClick;

	// time for smash
	float m_fTimeSmash;


	// timer game
	float m_ElapsedTime;

	// daan button
	cocos2d::MenuItemImage* m_DaanButton;

	// PUNCH BUTTON
	cocos2d::MenuItemImage* m_PunchButton;

	// move forward button
	cocos2d::MenuItemImage* m_MoveForwardButton;


	// move forward button
	cocos2d::MenuItemImage* m_MoveDownWardButton;

	// move forward button
	cocos2d::MenuItemImage* m_BlockButton;

	// reference to the arbiter
	cocos2d::Sprite* m_pAribiter;


public:

	static cocos2d::Scene* createScene();


	// the width of the screen
	static float getWidth();

	// the heiht of the screen
	static float getHeight();

	virtual bool init();

	// a selector callback
	void menuCloseCallback(cocos2d::Ref* pSender);

	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);

	// this function move the wrestler forward(avancer)
	void moveForward(cocos2d::Ref* pSender);

	// this function move the wrestler Downward(reculer)
	void moveDownward(cocos2d::Ref* pSender);


	// this function make the main  wrestler grab
	void grab(cocos2d::Ref* pSender);

	// this function make the main  wrestler punch
	void punch(cocos2d::Ref* pSender);

	// this function make the main  wrestler uppercut
	void uppercut(cocos2d::Ref* pSender);


	// this function makes the main wrestler 'daan'
	void block(cocos2d::Ref* pSender);

	// this function make the main  wrestler smash
	void smash(cocos2d::Ref* pSender);

	// this function makes the main wrestler 'daan'
	void daan(cocos2d::Ref* pSender);


	// update
	// called once per frame
	virtual void update(float dt);


	// ai management
	// this is core function of the game for managing ai
	void updateAI(float dt);

	// move the ai
	void moveAIForward();

	// implement the "static create()" method manually
	CREATE_FUNC(GameWorld);


	// UI AND DESIGN

	void addIconWrestlerLeft();

	void addIconWrestlerRight();

	void addIconStaminaLeft();

	void addIconStaminaRight();

	void addLabelPower();

	void updateLabelPower(float dt);

	void addLabelDamage();

	void updateLabelDamage(float dt);

	void addLabelEnergy();
	void updateLabelEnergy(float dt);


	// for 
	void addLoadingBar();

	// for smash
	bool getInputDaan(){ return m_bInputSmash; }


	float getTimeSmash(){ return m_fTimeSmash; }
	void setTimeSmash(float time){ m_fTimeSmash = time; }



	float getElapsedTime(){ return m_ElapsedTime; }
	void setElapsedTime(float time){ m_ElapsedTime = time; }


	// for daan
	bool getInputDaan1(){ return m_bInputDaan; }

	void ActivateAllButtons();
	void desactivateAllButtons();



	///////////////////// fx animation  ///////////////////

	void animateFXPunch(cocos2d::Vec2 pos);

	void animateFXUppercutGauche(cocos2d::Vec2 pos);

	void animateFXUppercutDroite(cocos2d::Vec2 pos);

	void animateFXEtourdi(cocos2d::Vec2 pos);

	void animateFXWalk(cocos2d::Vec2 pos);

	/////////////////// Arbiter//////////////


	public :
	void addArbiter();

	void updateArbiter(float dt);

	void arbiterFollow();

	void arbiterFinish();

	// the game has starded
	bool m_bGameStarted;

	// true if the arbiter has started
	bool m_bArbiterStart;

	// timer before following
	float m_fTimerArbiter;

	// timer before dance
	float m_fTimeBeforeDance;

	// true if the arbiter is following
	//bool m_bArbiter

	public :


	// reference to the arbiter
	cocos2d::Sprite* getArbiter(){ return m_pAribiter; }




};

#endif // __HELLOWORLD_SCENE_H__

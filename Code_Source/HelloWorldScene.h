//#ifndef __HELLOWORLD_SCENE_H__
//#define __HELLOWORLD_SCENE_H__
//
//#include "cocos2d.h"
//
//class Lutteur;
//
//
//class HelloWorld : public cocos2d::Layer
//{
//
//private:
//
//	// a pointer to the main pointer
//	Lutteur* m_pMainLutteur;
//
//	// a pointer to the ia
//	Lutteur* m_pIALuttueur;
//
//	// timeremaining before activating input for punch
//	float m_fTimeRemainPunch;
//
//	// timeremaining before activating punch for AI
//	float m_fTimeRemainPunchIA;
//
//	// true if punch putton is pressed
//	bool m_bPunchPressed;
//
//	// count the number of time the ai punches
//	int m_iNumberPunch;
//
//	// true if the input daan is pressed
//	bool m_bInputSmash;
//
//	// time for smash
//	float m_fTimeSmash;
//
//
//	// timer game
//	float m_ElapsedTime;
//
//
//public:
//
//    static cocos2d::Scene* createScene();
//
//
//	static float getWidth();
//
//    virtual bool init();
//    
//    // a selector callback
//    void menuCloseCallback(cocos2d::Ref* pSender);
//
//
//	// this function move the wrestler forward(avancer)
//	void moveForward(cocos2d::Ref* pSender);
//
//	// this function move the wrestler Downward(reculer)
//	void moveDownward(cocos2d::Ref* pSender);
//  
//
//	// this function make the main  wrestler grab
//	void grab(cocos2d::Ref* pSender);
//
//	// this function make the main  wrestler punch
//	void punch(cocos2d::Ref* pSender);
//
//	// this function make the main  wrestler uppercut
//	void uppercut(cocos2d::Ref* pSender);
//
//
//	// this function make the main  wrestler smash
//	void smash(cocos2d::Ref* pSender);
//
//
//	// update
//	// called once per frame
//	virtual void update(float dt);
//
//
//	// ai management
//	// this is core function of the game for managing ai
//	void updateAI(float dt);
//
//	// move the ai
//	void moveAIForward();
//	
//    // implement the "static create()" method manually
//    CREATE_FUNC(HelloWorld);
//
//
//	// UI AND DESIGN
//
//	void addIconWrestlerLeft();
//
//	void addIconWrestlerRight();
//
//	void addIconStaminaLeft();
//
//	void addIconStaminaRight();
//
//	void addLabelPower();
//
//	void updateLabelPower(float dt);
//
//	void addLabelDamage();
//
//	void updateLabelDamage(float dt);
//
//	void addLabelEnergy();
//	void updateLabelEnergy(float dt);
//
//
//	// for 
//	void addLoadingBar();
//
//	bool getInputDaan(){ return m_bInputSmash; }
//
//
//	float getTimeSmash(){ return m_fTimeSmash; }
//	void setTimeSmash(float time){ m_fTimeSmash = time; }
//
//
//
//	float getElapsedTime(){ return m_ElapsedTime; }
//	void setElapsedTime(float time){ m_ElapsedTime = time; }
//
//};
//
//#endif // __HELLOWORLD_SCENE_H__

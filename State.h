#pragma once
#include "IBehaviour.h"
#include "DynamicArray.h"
#include "Renderer2D.h"
#include "Agent.h"
using namespace aie;

class StateMachine;

class State
{
protected:
	bool isPause;

public:
	
	//----------------------------------------------------
	// Default Constructor
	//----------------------------------------------------
	State();
	
	//----------------------------------------------------
	// Default Destructor
	//----------------------------------------------------
	~State();

	//----------------------------------------------------
	// functions to run when entering state
	// params:
	//		takes in the state machine so it can call from its functions
	//----------------------------------------------------
	virtual void OnEnter(StateMachine* pMachine) = 0;
	
	//----------------------------------------------------
	// Update state when update function is called in State Machine
	// params:
	//		DeltaTime: to make everything in seconds
	//		takes in the state machine so it can call from its functions
	//----------------------------------------------------
	virtual void OnUpdate(float fDeltaTime, StateMachine* pMachine, Agent* pAgent) = 0;
	
	//----------------------------------------------------
	// Draw functions to run when draw function is called from state machine
	// params:
	//		takes in the state machine so it can call from its functions
	//----------------------------------------------------
	virtual void OnDraw(Renderer2D* m_2dRenderer) = 0;
	
	//----------------------------------------------------
	// functions to run when exiting state
	// params:
	//		takes in the state machine so it can call from its functions
	//----------------------------------------------------
	virtual void OnExit(StateMachine* pMachine) = 0;



protected:

	DynamicArray<IBehaviour*> m_pBehaviourList;
};


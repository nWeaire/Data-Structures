#pragma once
#include "Renderer2D.h"
#include "DynamicArray.h" 
#include "State.h"
#include "Stack.h"
using namespace aie;

class StateMachine
{
public:

	//----------------------------------------------------
	// default constructor
	//----------------------------------------------------
	StateMachine();

	//----------------------------------------------------
	// default destructor
	//----------------------------------------------------
	~StateMachine();

	//----------------------------------------------------
	// Calls update on top state
	// parameters:
	//			deltaTime: Float to make everything in seconds
	//----------------------------------------------------
	void Update(float deltaTime, Agent* pAgent);
	
	//----------------------------------------------------
	// Checks if onoff is true
	// Draws first and second state if true
	// Draws top if false
	// parameters:
	//			m_2dRenderer: bootstrap renderer
	//----------------------------------------------------
	void Draw(Renderer2D* m_2dRenderer);
	
	//----------------------------------------------------
	// pushes a state onto the stack
	// parameters:
	//			nStateIndex: index to correspond to what state to push onto the stack
	//----------------------------------------------------
	void PushState(int nStateIndex);
	
	//----------------------------------------------------
	// Adds a state to the list of states
	// parameters:
	//			nStateIndex: index to add state to in array
	//			pState: pointer to state
	//----------------------------------------------------
	void AddState(int nStateIndex, State* pState);
	
	//----------------------------------------------------
	// pops top state off stack
	//----------------------------------------------------
	void PopState();
	
	//----------------------------------------------------
	// Sets a bool to determine whether to render more then one state at a time
	// parameters:
	//			onoff: bool to determine whether to render the state below or not
	//----------------------------------------------------
	void SetBackgroundRender(bool onoff);

	
private:
	// bool for use in background render function
	bool onoff = false;

	// dynamic array of states
	DynamicArray<State*> m_StateList;

	// Stack of states.
	Stack<State*> m_CurrentStack;
};
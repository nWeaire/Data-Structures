#include "StateMachine.h"
#include <crtdbg.h>
#include "Renderer2D.h"

using namespace aie;

//----------------------------------------------------
// default constructor
//----------------------------------------------------
StateMachine::StateMachine()
{
}

//----------------------------------------------------
// default destructor
//----------------------------------------------------
StateMachine::~StateMachine()
{
	while (m_CurrentStack.size() > 0)
		PopState();

	for (int i = 0; i < m_StateList.Size(); ++i)
	{
		delete m_StateList[i];
	}
}

//----------------------------------------------------
// Calls update on top state
// parameters:
//			deltaTime: Float to make everything in seconds
//----------------------------------------------------
void StateMachine::Update(float deltaTime, Agent* pAgent)
{
	if (m_CurrentStack.size() <= 0)
		return;
	

	m_CurrentStack.top()->OnUpdate(deltaTime, this, pAgent);

}

//----------------------------------------------------
// Checks if onoff is true
// Draws first and second state if true
// Draws top if false
// parameters:
//			m_2dRenderer: bootstrap renderer
//----------------------------------------------------
void StateMachine::Draw(Renderer2D* m_2dRenderer)
{
	if (m_CurrentStack.size() <= 0)
		return;

	if (onoff == true)
	{
		m_CurrentStack.SecondLast()->OnDraw(m_2dRenderer);
	}

	m_CurrentStack.top()->OnDraw(m_2dRenderer);

}

//----------------------------------------------------
// pushes a state onto the stack
// parameters:
//			nStateIndex: index to correspond to what state to push onto the stack
//----------------------------------------------------
void StateMachine::PushState(int nStateIndex)
{
	// Example of Assert
	/*_ASSERT(nStateIndex < m_StateList.Size());
	if (nStateIndex >= m_StateList.Size())
		return;*/

	if (m_CurrentStack.size() > 0)
		m_CurrentStack.top()->OnExit(this);

	m_CurrentStack.push(m_StateList[nStateIndex]);
	m_CurrentStack.top()->OnEnter(this);
}

//----------------------------------------------------
// pops top state off stack
//----------------------------------------------------
void StateMachine::PopState()
{
	if (m_CurrentStack.size() > 0)
		m_CurrentStack.top()->OnExit(this);
	
	m_CurrentStack.pop();
	if (m_CurrentStack.size() > 0)
		m_CurrentStack.top()->OnEnter(this);
}

//----------------------------------------------------
// Sets a bool to determine whether to render more then one state at a time
// parameters:
//			onoff: bool to determine whether to render the state below or not
//---------------------------------------------------- 
void StateMachine::SetBackgroundRender(bool onoff)
{
	this->onoff = onoff; 
}

//----------------------------------------------------
// Adds a state to the list of states
// parameters:
//			nStateIndex: index to add state to in array
//			pState: pointer to state
//----------------------------------------------------
void StateMachine::AddState(int nStateIndex, State* pState)
{
	m_StateList.Insert(nStateIndex, pState); // Adds state to an array of states
}
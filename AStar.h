#pragma once
#include "aStarHeap.h"
#include "DynamicArray.h"

struct aStarNode;

// Function Pointer for custom heuristic
typedef int(*CalcHeur)(aStarNode*, aStarNode*);

class AStar
{
public:

	//-------------------------------------
	//	Constructor
	//	Params:
	//			nMaxNodes: int of max nodes of aStar path
	//-------------------------------------
	AStar(int nMaxNodes);

	//-------------------------------------
	// Default Destructor
	//-------------------------------------
	~AStar();


	//-------------------------------------
	// Calculates a path for an agent
	// params:
	//		pStart: Starting node for aStar path
	//		pEnd: Ending node for aStar path
	//		finishedPath: a dynamic array to store the nodes of the finished aStar path
	// returns:
	//		bool: if path is possible or not
	//
	//-------------------------------------
	bool CalculatePath(aStarNode* pStart, aStarNode* pEnd, DynamicArray<aStarNode*>* finishedPath);
	
	//-------------------------------------
	// sets the calculate heuristic function to function pointer
	// params:
	//		func: variable to store function
	//-------------------------------------
	void setFucntion(CalcHeur func);

	//-------------------------------------
	// Checks if function is valid and calls it
	// params:
	//		pStart: Starting node for heuristic
	//		pEnd: Ending node for heuristic
	// returns:
	//		int: returns the heuristic value or 0 if there is none
	//
	//-------------------------------------
	int callFunction(aStarNode* pStart, aStarNode* pEnd);
	

protected:
	// list of aStarHeaps
	aStarHeap m_OpenList;
	
	// list of checked nodes
	bool* m_ClosedList;
	
	// Max nodes available in a star path
	int maxNodes;

	// Function pointer for heuristic
	CalcHeur myHeuristic = nullptr;
};


#include "AStar.h"
#include "GridNode.h"
#include <math.h>

//-------------------------------------
// sets the calculate heuristic function to function pointer
// params:
//		func: variable to store function
//-------------------------------------
void AStar::setFucntion(CalcHeur func)
{
	// Sets function pointer
	myHeuristic = func;

}

//-------------------------------------
// Checks if function is valid and calls it
// params:
//		pStart: Starting node for heuristic
//		pEnd: Ending node for heuristic
// returns:
//		int: returns the heuristic value or 0 if there is none
//
//-------------------------------------
int AStar::callFunction(aStarNode* pStart, aStarNode* pEnd)
{
	// Checks if function is valid and calls it
	if (myHeuristic)
		return myHeuristic(pStart, pEnd);
	else
		return 0;
}


//-------------------------------------
//	Constructor
//	Params:
//			nMaxNodes: int of max nodes of aStar path
//-------------------------------------
AStar::AStar(int nMaxNodes)
{
	// Creates closed list of bools
	m_ClosedList = new bool[nMaxNodes];

	// Sets maxNodes from user input
	maxNodes = nMaxNodes;
}


//-------------------------------------
// Default Destructor
//-------------------------------------
AStar::~AStar()
{
	delete[] m_ClosedList; // Delete to avoid memory leaks
}


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
bool AStar::CalculatePath(aStarNode* pStart, aStarNode* pEnd, DynamicArray<aStarNode*>* finishedPath)
{
	// Clear open list
	m_OpenList.Clear();
	// Set all elements in closed list to false
	memset(m_ClosedList, 0, sizeof(bool) * maxNodes);

	// Set start node's G score to zero
	pStart->m_nGScore = 0;
	// Calculate start node's H score(for now set to zero)
	pStart->m_nHScore = callFunction(pStart, pEnd);
	// Calculate start node's F score
	pStart->m_nFScore = pStart->m_nGScore + pStart->m_nHScore;
	// Set start node's m_pPrev to null.
	pStart->m_pPrev = nullptr;
	// Add Start node to open list
	m_OpenList.Push(pStart);

	// While there are still nodes in the open list
	
	while (m_OpenList.GetSize() > 0)
	{
		// Get the node from the open list with the lowest F score, call it currentNode.
		aStarNode* currentNode = m_OpenList.Pop();
		// add currentNode to the closed list (by setting the indexed bool to true)
		m_ClosedList[currentNode->m_nIndex] = true;
		// if currentNode is the end node, we are finished
		if (currentNode == pEnd)
		{
			// Build path ( remember it is backwards so we need to fix that)
			aStarNode* pNode = pEnd;
			do
			{
				finishedPath->pushFront(pNode);
				pNode = pNode->m_pPrev;
			} 
			while (pNode);
			return true;
		}


		// loop through all of currentNode's neighbours
		for(int i = 0; i < currentNode->m_AdjacentList.Size(); ++i)
		{
			// Get neighbour
			aStarNode* currentAdj = currentNode->m_AdjacentList[i]->m_pEndNode;

			int nCost = currentNode->m_AdjacentList[i]->m_nCost;

			// Skip walls
			if (currentAdj->m_bBlocked)
			{
				continue;	
			}

			// Skip neighbours that are already in the closed list
			if (m_ClosedList[currentAdj->m_nIndex])
			{
				continue;
			}

			// if neighbour is already in open list...
			if (m_OpenList.Contains(currentAdj))
			{
				// Check if this current path is better then old path (lower F score).
				if (currentNode->m_nFScore + nCost < currentAdj->m_nFScore)
				{
					// Update G score.
					currentAdj->m_nGScore = currentNode->m_nGScore + nCost;
					// Update F score.
					currentAdj->m_nFScore = currentAdj->m_nGScore + currentAdj->m_nHScore;
					// Update Prev Node.
					currentAdj->m_pPrev = currentNode;

					// sort heap

				}
					
			}
			else
			{
					// Calculate G score
				currentAdj->m_nGScore = currentNode->m_nGScore + nCost;
					// Calculate H score
				currentAdj->m_nHScore = callFunction(pStart, pEnd);
					// Calculate F score
				currentAdj->m_nFScore = currentAdj->m_nGScore + currentAdj->m_nHScore;
					// Set Prev node pointer
				currentAdj->m_pPrev = currentNode;
					// add neighbour to open list
				m_OpenList.Push(currentAdj);
			}
		}
	}
	// no path found if we got to here, so return false.
	return false;
}





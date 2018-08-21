#pragma once

#include "DynamicArray.h"

struct aStarNode;

// AstarEdge struct Containing Endnode and cost of AstarNodes
struct aStarEdge
{
	aStarNode* m_pEndNode;
	int m_nCost;


};

// Struct containing the aStarNodes data
struct aStarNode
{
public:

	aStarNode(int nIndex)
	{
		m_bBlocked = false;
		m_pPrev = nullptr;
		m_nGScore = 0;
		m_nHScore = 0;
		m_nFScore = 0;
		m_nIndex = nIndex;
		
	}


	// pointer to the previous node
	aStarNode* m_pPrev;

	// ints containing G, H and F Scores
	int m_nGScore;
	int m_nHScore;
	int m_nFScore;
	
	// Index of nodes
	int m_nIndex;

	bool m_bBlocked;

	DynamicArray<aStarEdge*> m_AdjacentList;

	// destructor, deletes entire list
	virtual ~aStarNode()
	{
		for (int i = 0; i < m_AdjacentList.Size(); ++i)
		{
			delete m_AdjacentList[i];
		}
	}
};


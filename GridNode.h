#pragma once

#include "aStarNode.h"
#include "Vector2.h"

//Struct for GridNode inheriting from aStarNode
struct GridNode : public aStarNode
{
public:

	//-------------------------------------
	// Constructor
	// params:
	//		pos: Vector2 storing the position of the grid node
	//		nIndexX: the x position of the grid
	//		nIndexY: the y position of the grid
	//		nIndex: nodes overall position
	//
	//
	//-------------------------------------
	GridNode(Vector2 pos, int nIndex, int nIndexX, int nIndexY) : aStarNode(nIndex)
	{
		m_v2Pos = pos;
		m_nIndexX = nIndexX;
		m_nIndexY = nIndexY;

	}

	
	int m_nIndexX;
	int m_nIndexY;

	Vector2 m_v2Pos;
};


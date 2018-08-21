#pragma once
#include "Renderer2D.h"
#include "aStarNode.h"
#include "GridNode.h"
#include "Defines.h"
#include "AStar.h"


using namespace aie;


// Class which creates and defines the grid
class Grid
{
public:
	
	//-------------------------------------
	// Draws 
	// params:
	//		m_2dRenderer: renderer which controls the generating of sprites
	//-------------------------------------
	void drawGrid(Renderer2D* m_2dRenderer);
	

	//-------------------------------------
	// Returns node at given index
	// params:
	//		index: 
	// returns:
	//		bool: if path is possible or not
	//
	//-------------------------------------
	GridNode* getNode(int index);

	//-------------------------------------
	// default Constructor
	//-------------------------------------
	Grid();

	//-------------------------------------
	// default Destructor 
	//-------------------------------------
	~Grid();
private:
	
	GridNode** m_ppGrid;
	AStar* m_pAStar;





};


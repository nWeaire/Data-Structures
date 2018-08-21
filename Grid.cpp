#include "Grid.h"
#include <math.h>
#include <crtdbg.h>



//-------------------------------------
// default Constructor
//-------------------------------------
Grid::Grid()
{
	// Creates new grid of specified size
	m_ppGrid = new GridNode*[GRID_SIZE * GRID_SIZE];
	
	for (int x = 0; x < GRID_SIZE; ++x)
	{
		for (int y = 0; y < GRID_SIZE; ++y)
		{
			int index = (y * GRID_SIZE) + x;

			Vector2 pos(x * NODE_SIZE, y * NODE_SIZE);
			m_ppGrid[index] = new GridNode(pos, index, x, y);

			
		}
	}

	// Creates all Walls that the AI cant pass through
	//-------------------------------------------------
	m_ppGrid[11]->m_bBlocked = true;
	m_ppGrid[12]->m_bBlocked = true;
	m_ppGrid[13]->m_bBlocked = true;
	m_ppGrid[14]->m_bBlocked = true;
	m_ppGrid[15]->m_bBlocked = true;
	m_ppGrid[16]->m_bBlocked = true;
	m_ppGrid[17]->m_bBlocked = true;
	m_ppGrid[18]->m_bBlocked = true;
	m_ppGrid[21]->m_bBlocked = true;
	m_ppGrid[31]->m_bBlocked = true;
	m_ppGrid[41]->m_bBlocked = true;
	m_ppGrid[51]->m_bBlocked = true;
	m_ppGrid[61]->m_bBlocked = true;
	m_ppGrid[71]->m_bBlocked = true;
	m_ppGrid[81]->m_bBlocked = true;
	m_ppGrid[82]->m_bBlocked = true;
	m_ppGrid[83]->m_bBlocked = true;
	m_ppGrid[84]->m_bBlocked = true;
	m_ppGrid[85]->m_bBlocked = true;
	m_ppGrid[86]->m_bBlocked = true;
	m_ppGrid[87]->m_bBlocked = true;
	m_ppGrid[88]->m_bBlocked = true;
	m_ppGrid[28]->m_bBlocked = true;
	m_ppGrid[38]->m_bBlocked = true;
	m_ppGrid[48]->m_bBlocked = true;
	m_ppGrid[68]->m_bBlocked = true;
	m_ppGrid[78]->m_bBlocked = true;
	m_ppGrid[88]->m_bBlocked = true;
	//-------------------------------------------------



	for (int x = 0; x < GRID_SIZE; ++x)
	{
		for (int y = 0; y < GRID_SIZE; ++y)
		{
			int index = (y * GRID_SIZE) + x;

			GridNode* currentNode = m_ppGrid[index];
			// -------------
			// |   | 3 |   |
			// -------------
			// | 0 | C | 2 |
			// -------------
			// |   | 1 |   |
			// -------------
			// Adjacent Nodes
			for (int a = 0; a < 4; ++a)
			{
				int localX = x;
				int localY = y;

				if (a % 2 == 0)
				{
					localX += a - 1;
				}
				else
				{
					localY += a - 2;
				}

				if (localX < 0 || localX >= GRID_SIZE)
					continue;

				if (localY < 0 || localY >= GRID_SIZE)
					continue;


				int localIndex = (localY * GRID_SIZE) + localX;
				GridNode* adjNode = m_ppGrid[localIndex];

				aStarEdge* pEdge = new aStarEdge();
				pEdge->m_pEndNode = adjNode;
				pEdge->m_nCost = 10;

				currentNode->m_AdjacentList.pushBack(pEdge);
			}

			// Diagonal Nodes
			// -------------
			// | 1 |   | 2 |
			// -------------
			// |   | C |   |
			// -------------
			// | 0 |   | 3 |
			// -------------
			for (int d = 0; d < 4; ++d)
			{
				int localX = x;
				int localY = y;

				if (d % 2 == 0)
				{
					localX += d - 1;
					localY += d - 1;
				}
				else
				{
					localX += d - 2;
					localY -= d - 2;

				}

				if (localX < 0 || localX >= GRID_SIZE)
					continue;

				if (localY < 0 || localY >= GRID_SIZE)
					continue;


				int localIndex = (localY * GRID_SIZE) + localX;
				GridNode* adjNode = m_ppGrid[localIndex];

				aStarEdge* pEdge = new aStarEdge();
				pEdge->m_pEndNode = adjNode;
				pEdge->m_nCost = 14;

				currentNode->m_AdjacentList.pushBack(pEdge);
			}


		}
	}



	//m_pAStar = new AStar(GRID_SIZE * GRID_SIZE);

	
}

//-------------------------------------
// default Destructor 
//-------------------------------------
Grid::~Grid()
{
	for (int i = 0; i < GRID_SIZE * GRID_SIZE; ++i)
	{
		delete m_ppGrid[i];
	}
	delete[] m_ppGrid;

}

//-------------------------------------
// Draws 
// params:
//		m_2dRenderer: renderer which controls the generating of sprites
//-------------------------------------
void Grid::drawGrid(Renderer2D* m_2dRenderer)
{

	for (int i = 0; i < GRID_SIZE * GRID_SIZE; ++i)
	{
		float x = m_ppGrid[i]->m_v2Pos.x;
		float y = m_ppGrid[i]->m_v2Pos.y;

		if (m_ppGrid[i]->m_bBlocked)
		{
			m_2dRenderer->setRenderColour(0xa9a9a9FF);
		}
		else
		{
			m_2dRenderer->setRenderColour(0xFFFFFFFF);
		}

			m_2dRenderer->drawBox(x, y, NODE_SIZE - 5, NODE_SIZE - 5);

		for (int a = 0; a < m_ppGrid[i]->m_AdjacentList.Size(); ++a)
		{
			GridNode* otherNode = ((GridNode*)m_ppGrid[i]->m_AdjacentList[a]->m_pEndNode);

			float otherX = otherNode->m_v2Pos.x;
			float otherY = otherNode->m_v2Pos.y;


			/*m_2dRenderer->setRenderColour(0xFF0000FF);
			m_2dRenderer->drawLine(x, y, otherX, otherY, 2.0f);
			m_2dRenderer->setRenderColour(0xFFFFFFFF);*/
		}
	}
	// Draw Path
	/*DynamicArray<aStarNode*> path;
	m_pAStar->CalculatePath(m_ppGrid[1], m_ppGrid[98], &path);

	for (int i = 0; i < path.Size(); ++i)
	{
		GridNode* pNode = (GridNode*)path[i];

		m_2dRenderer->setRenderColour(0x00FF00FF);
		m_2dRenderer->drawBox(pNode->m_v2Pos.x, pNode->m_v2Pos.y, NODE_SIZE / 2, NODE_SIZE / 2);
		m_2dRenderer->setRenderColour(0xFFFFFFFF);
	}*/
}

//-------------------------------------
// Returns node at given index
// params:
//		index: 
// returns:
//		bool: if path is possible or not
//
//-------------------------------------
GridNode* Grid::getNode(int index)
{



	return m_ppGrid[index];
}


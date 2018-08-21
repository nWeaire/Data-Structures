#pragma once
#include "GraphNode.h"
#include "LinkedList.h"
#include "Stack.h"
template <typename T>
class Graph
{
public:
	Graph()
	{

	}

	~Graph()
	{

	}

	void Insert(GraphNode<T>* node)
	{
		m_Nodes.PushBack(node);
	}

	void Remove(GraphNode<T>* node)
	{

	}

	void Remove(T data)
	{

	}

	/*void DrawGraph(aie::Renderer2D* m_2dRenderer)
	{
		for (int i = 0; i < m_Nodes.Size(); ++i)
		{
			m_Nodes[i]->m_bTraversed = false;
		}

		Stack<GraphNode<T>*> stack;

		stack.push(m_Nodes[0]);

		while (!stack.empty())
		{
			GraphNode<T>* current = stack.pop();
			current->m_bTraversed = true;

			std::cout << current->m_Data << std::endl;
			


			for (int i = 0; i < current->m_Edges.Size; ++i)
			{
				if(!current->m_Edges[i]->m_bTraversed)
				stack.push(current->m_Edges[i]);
			}
		}
	}*/


private:
	LinkedList<GraphNode<T>*> m_Nodes;



};
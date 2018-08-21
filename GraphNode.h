#pragma once
#include "LinkedList.h"
template <typename T>
class GraphNode
{
public:
	GraphNode()
	{
	}

	GraphNode(T data)
	{
		m_Data = data;
	}

	GraphNode()
	{
	}

	void AddConnection(GraphNode<T>* other)
	{
		m_Edges.PushBack(other);
	}

	void RemoveConnection(GraphNode<T>* other)
	{
		m_Edges.remove(other);
	}

	LinkedList<GraphNode<T>*> m_Edges;
	T m_Data;
	bool m_bTraversed;
};
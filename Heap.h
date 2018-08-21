#pragma once

#include <math.h>
#include "DynamicArray.h"
template <typename T>
class Heap
{
public:
	//-------------------------------------
	// Default Constructor
	//-------------------------------------
	Heap()
	{
	}

	//-------------------------------------
	// Default Destructor
	//-------------------------------------
	~Heap()
	{

	}

	//-------------------------------------
	// Adds data to heap
	// sorts heap from smallest to largest
	// params:
	//		data: Templated value to add to heap
	//-------------------------------------
	void Push(T data)
	{
		// Add data to end of array
		m_Data.pushBack(data);

		// Loop through and swap parent if data is smaller
		int current = m_Data.Size() - 1;
		while (true)
		{
			if (current == 0)
				break;

			int parent = GetParentIndex(current);

			//Checks if new value is smaller and sorts accordingly
			if (m_Data[current] < m_Data[parent])
			{
				T swap = m_Data[current];
				m_Data[current] = m_Data[parent];
				m_Data[parent] = swap;

				current = parent;
			}
			else
				break;
		}
	}
	
	//-------------------------------------
	// removes the value on top of heap and resorts
	// returns:
	//		T: returns templated value from heap
	//-------------------------------------
	T Pop()
	{
		T result = m_Data[0];
		// replace first element with last element
		int last = m_Data.Size() - 1;
		m_Data[0] = m_Data[last];


		// swap first element with smaller child if child is smaller
		int current = 0;

		while (true)
		{
			int child0 = getChildIndex(current, 1);
			if (child0 > last)
				break;


			int child1 = getChildIndex(current, 2);
			int smallerChild = child0;
			if (child1 <= last && m_Data[child1] < m_Data[smallerChild])
				smallerChild = child1;
			
			if (m_Data[smallerChild] < m_Data[current])
			{
				T swap = m_Data[current];
				m_Data[current] = m_Data[smallerChild];
				m_Data[smallerChild] = swap;

				current = smallerChild;
			}
			else
				break;
		}
		//repeat
		m_Data.popBack();
		return result;
	}

	//-------------------------------------
	// Calls clear function from Dynamic array functions
	//-------------------------------------
	void Clear()
	{
		m_Data.Clear();
	}

	//-------------------------------------
	// Calls Size function from dynamic array
	//-------------------------------------
	int GetSize()
	{
		return (int)m_Data.Size();
	}

	//-------------------------------------
	// Returns the parent index
	// params:
	//		childIndex: 
	// returns:
	//		int: returns parent index
	//
	//-------------------------------------
	int GetParentIndex(int childIndex)
	{
		return (childIndex - 1) / 2;
	}

	//-------------------------------------
	// Returns the childs index
	// params:
	//		parentIndex: int for which parent 		
	//		whichChild: int for which child
	// returns:
	//		int: returns index of a child
	//
	//-------------------------------------
	int getChildIndex(int parentIndex, int whichChild)
	{
		return (2 * parentIndex) + whichChild;
	}

	//-------------------------------------
	// Checks if pData is in the heap
	// params:
	//		pData: Checks if pData is in the heap
	// returns:
	//		bool: returns true if there in the heap
	//
	//-------------------------------------
	bool Contains(T* pData)
	{
		for (int i = 0; i < m_Data.Size(); ++i)
		{
			if (m_Data[i] == pData)
				return true;
		}
		return false;
	}

private:
	// Dynamic array of Data
	DynamicArray<T> m_Data;

};

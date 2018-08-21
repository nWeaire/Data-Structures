#pragma once
#include "LinkedList.h"

template <typename T>
class Queue
{
public:
	//----------------------------------------------------
	// Default constructor
	//----------------------------------------------------
	Queue()
	{
	}

	//----------------------------------------------------
	// Default destructor
	//----------------------------------------------------
	~Queue()
	{
	}

	//----------------------------------------------------
	// Calls PushBack() function from LinkList.h
	// params:
	//		value: Templated value to add to linked list
	//----------------------------------------------------
	void Push(T value)
	{
		q.PushBack(value);
	}

	//----------------------------------------------------
	// Calls First() function from LinkList.h
	// returns:
	//		T: Returns data of first object in queue
	//----------------------------------------------------
	T Top()
	{
		return q.First();
	}

	//----------------------------------------------------
	// Calls Size() function from LinkList.h
	// returns:
	//		int: Returns the size of the queue
	//----------------------------------------------------
	int size()
	{
		return q.Size();
	}

	//----------------------------------------------------
	// Calls Empty() function from LinkList.h
	// returns:
	//		bool: True or False for if the queue is empty or not
	//----------------------------------------------------
	bool empty()
	{
		return q.empty();
	}

	//----------------------------------------------------
	// Calls PopFront() function from LinkList.h
	// returns:
	//		T: value of top node
	//----------------------------------------------------
	T pop()
	{
		return q.popFront();
	}

	//----------------------------------------------------
	// Calls Clear() function from LinkList.h
	//----------------------------------------------------
	void clear()
	{
		q.clear();
	}

	//----------------------------------------------------
	// Calls printList() function from LinkList.h
	//----------------------------------------------------
	void printList()
	{
		q.printList();
	}

	//Linked list of templates for use in queue
	LinkedList<T> q;
};
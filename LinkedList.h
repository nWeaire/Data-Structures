#pragma once
#include "ListNode.h"
template <typename T>
class LinkedList
{
public:
	//----------------------------------------------------
	// Constructor
	// Creates linked list and sets starting next and prev pointers
	//----------------------------------------------------
	LinkedList() 
	{
		start = new ListNode<T>();
		end = new ListNode<T>();
		start->next = end;
		start->prev = nullptr;
		end->next = nullptr;
		end->prev = start;
	}
	
	//----------------------------------------------------
	// Default destructor
	// Deletes next and prev pointers
	//----------------------------------------------------
	~LinkedList() 
	{
		delete start;
		delete end;

	}

	//----------------------------------------------------
	// Inserts a node into the array and sets pointers so it fits in
	// params:
	//		Value: Template value to store in node
	//		Prev: Prev pointer in the list
	//		next: next pointer for list
	//----------------------------------------------------
	void insert(T value, ListNode<T>* prev, ListNode<T>* next)
	{
		ListNode<T>* n1 = new ListNode<T>();
		n1->data = value;
		n1->next = next;
		prev->next = n1;
		next->prev = n1;
		n1->prev = prev;
		++nodeCount;
	}

	//----------------------------------------------------
	// Calls insert() for the last index in the list
	// params:
	//		Value: Template value to store in node
	//----------------------------------------------------
	void PushBack(T value)
	{
		insert(value, end->prev, end);
	}
	
	//----------------------------------------------------
	// Calls insert() for first index in the list
	// params:
	//		Value: Template value to store in node
	//----------------------------------------------------
	void PushFront(T value)
	{
		insert(value, start, start->next);
	}

	//----------------------------------------------------
	// Inserts a node into the array at a given index
	// params:
	//		index: Int that determines location in list to insert node 
	//		value: Template value to store in node
	//----------------------------------------------------
	void IndexInsert(int index, T value)
	{
		ListNode<T>* current = start;
		for (int i = 0; i < index; ++i)
		{
			if (current->next == end)
			{
				cout << "Invalid index location!" << endl;
				return;
			}
			current = current->next;
		}
		insert(value, current, current->next);
	}

	//----------------------------------------------------
	// checks if list is empty
	// returns first value in the list
	// returns:
	//		T: templated value
	//----------------------------------------------------
	T First()
	{
		if (start->next == end)
		{
			cout << "This list is empty!" << endl;
			return default;
		}
		else
		{
			T value = start->next->data;
			return value;
		}
	}

	//----------------------------------------------------
	// checks if list is empty
	// returns last value in the list
	// returns:
	//		T: templated value
	//----------------------------------------------------
	T Last()
	{
		if (start->next == end)
		{
			cout << "This list is empty!" << endl;
			return default;
		}
		else
		{
			T value = end->prev->data;
			return value;
		}
	}

	//----------------------------------------------------
	// returns the size of the list
	// returns:
	//		nodeCount: returns the size of the list
	//----------------------------------------------------
	int Size()
	{
			return nodeCount;
	}

	//----------------------------------------------------
	// checks if list is empty
	// returns:
	//		true: returns true if list is empty
	//		false: returns false if list has data in it
	//----------------------------------------------------
	bool empty()
	{
		if (start->next == end)
			return true;
		else
			return false;
	}

	//----------------------------------------------------
	// removes the last node on the list
	// returns the data from the removed node
	// returns:
	//		tempData: Data from removed node
	//		default: if no data returns nothing
	//----------------------------------------------------
	T popBack()
	{
		ListNode<T>* n = end->prev;
		T tempData = n->data;
		if (n != start)
		{
			n->prev->next = end;
			end->prev = n->prev;
			delete n;
			--nodeCount;
			return tempData;
		}
		else
			return default;

		
	}

	//----------------------------------------------------
	// removes the first node on the list
	// returns the data from the removed node
	// returns:
	//		tempData: Data from removed node
	//		default: if no data returns nothing
	//----------------------------------------------------
	T popFront()
	{
		ListNode<T>* n = start->next;
		T tempData = n->data;
		if (n != end)
		{
			n->next->prev = start;
			start->next = n->next;
			delete n;
			--nodeCount;
			return tempData;
		}
		else
			return default;

	}

	//----------------------------------------------------
	// pops all nodes off the list
	// clears entire node
	//----------------------------------------------------
	void clear() 
	{
		while (start->next != end)
			popBack();
	}

	//----------------------------------------------------
	// erases a node from the list
	// Params:
	//		index: which node to remove in the list
	//----------------------------------------------------
	void erase(int index)
	{
		ListNode<T>* current = start;
		for (int i = 0; i < index; ++i)
		{
			if (current->next == end)
			{
				cout << "Invalid index location!" << endl;
				return;
			}
			current = current->next;
		}
		if (current == start || current == end)
		{
			cout << "Cannot delete start and end!" << endl;
			return;
		}
		current->next->prev = current->prev;
		current->prev->next = current->next;
		delete current;
		--nodeCount;
	}

	//----------------------------------------------------
	// removes all nodes with the given data
	// 
	// Params:
	//		value: value to check for in nodes
	//----------------------------------------------------
	void remove(T value)
	{
		ListNode<T>* temp = nullptr;
		ListNode<T>* current = start->next;
		while (current->next != end)
		{
			if (current->next == end)
			{
				cout << "Invalid index location!" << endl;
				return;
			}
			if (current->data == value)
			{
				temp = current->prev;
				current->next->prev = current->prev;
				current->prev->next = current->next;
				delete current;
				current = temp;
				--nodeCount;
			}
			current = current->next;
		}
	}
	
	//----------------------------------------------------
	// Prints all data from each node
	//----------------------------------------------------
	void printList()
	{
		ListNode<T>* current = start->next;
		while (current->next != end)
		{
			cout << current->data << endl;
			current = current->next;
		}
	}

	// int to count nodes
	int nodeCount = 0;

	// pointers for next and prev nodes
	ListNode<T>* start;
	ListNode<T>* end;
	
	// empty value for error checking 
	T default; 
};


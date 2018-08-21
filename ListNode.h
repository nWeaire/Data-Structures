#pragma once

template <typename T>
class ListNode
{

public: 
	
	//----------------------------------------------------
	// Default Constructor
	//----------------------------------------------------
	ListNode() {};

	//----------------------------------------------------
	// Default Destructor
	//----------------------------------------------------
	~ListNode() {};

	// Data to be held in each node
	T data;

	// Pointers for the next and prev node
	ListNode* next;
	ListNode* prev;
};
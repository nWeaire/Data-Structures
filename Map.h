#pragma once
#include "DynamicArray.h"
#include <iostream>
using namespace std;

template <typename T>
class Map
{
private:

	// Struct holding name and data
	typedef struct _Data
	{
		T data;
		char* name;
	} Data;
	
	// DynamicArray of data
	DynamicArray<Data> stack;

public:

	//----------------------------------------------------
	// clears the entire stack
	//----------------------------------------------------
	void Clear()
	{
		stack.Clear();
	}

	//----------------------------------------------------
	// functions to run when exiting state
	// return:
	//		long: Returns size of map
	//----------------------------------------------------
	long Size()
	{
		return stack.Size();
	}

	//----------------------------------------------------
	// Checks if item exists
	// return:
	//		bool: Returns bool if item exists
	// Params:
	//		name: Char* to check for array
	//----------------------------------------------------
	bool IsItem(char* name)
	{
		for (int i = 0; i<Size(); i++)
		{
			if (stack[i].name == name)
				return true;
		}
		return false;
	}

	//----------------------------------------------------
	// Adds item to Dynamic array
	// params:
	//		name: string of chars
	//		data: data to be held in node
	// return:
	//		
	//---------------------------------------------------- 
	bool AddItem(char* name, T data)
	{
		if (IsItem(name))
			return false;
		Data d;
		d.name = name;
		d.data = data;
		stack.pushBack(d);
		return true;
	}

	//----------------------------------------------------
	// Operator overload
	// returns:
	//		d: templated data
	// Params:	
	//		name: Pointer to char name
	//----------------------------------------------------
	T& operator [] (char* name)
	{
		for (int i = 0; i<Size(); i++)
		{
			if (stack[i].name == name)
				return stack[i].data;
		}
		long idx = Size();
		Data d;
		d.name = name;
		stack.pushBack(d);
		return stack[idx].data;
	}

	//----------------------------------------------------
	// returns the name of the item at a certain index
	// params:
	//		index: takes in a number that corresponds to an index in array
	// returns:
	//		Char* name: returns the name of the item in the index
	//----------------------------------------------------
	char* GetItemName(long index)
	{
		if (index<0)
			index = 0;
		for (int i = 0; i<Size(); i++)
			if (i == index)
				return stack[i].name;
		return "";
	}

	//----------------------------------------------------
	// Operator overload for creating map
	// params:
	//		index: Long int for spot in array
	// returns:
	//		data: returns the data value of indexed item
	//----------------------------------------------------
	T& operator [] (long index)
	{
		if (index < 0)
			index = 0;
		for (int i = 0; i<Size(); i++)
		{
			if (i == index)
				return stack[i].data;
		}
		return stack[0].data;
	}

};
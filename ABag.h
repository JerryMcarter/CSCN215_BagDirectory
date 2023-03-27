//Jeremiah Carter - CSCN215 - LAB 1

#pragma once 

//#include <memory>
#include <stdlib.h>
#include "kvpair.h"
#include "bagADT.h"

template <typename E>

class ABag : public Bag<E> {

private:
	// private members
	std::unique_ptr<E[]> stackArray;

	// maximum capacity of the array
	int capacity;

	// current items in array
	int currSize;

public:

	// a user catered constructor with custom size
	ABag<E>(int size=10) {
		capacity = size;
		currSize = 0;

		stackArray = std::make_unique<E[]>(capacity);
	}

	// deconstructor
	~ABag<E>() {}

	// adds item to stack
	bool addItem(const E& item)
	{
		// if the current number of element in stack does not exceed
		// the capacity, add item to stack and return true.
		if (currSize < capacity)
		{
			stackArray[currSize++] = item;

			return true;
		}

		// otherwise return false
		return false;

	}

	// remove a particular item from the stack
	bool remove(E& item) {
	
		// traverse the stack
		for (int j = 0; j < currSize; j++)
		{
			// if the item is the same as the element in the current position
			if (stackArray[j] == item) 
			{
				// update
				item = stackArray[j];

				// shift all the other elements left
				for (int y = j; y < currSize - 1; y++)
				{
					stackArray[y] = stackArray[y + 1];
				}

				currSize--; //logical remove of value

				return true;
			}
		}

		return true;
	}

	// "popping" the item on top of the stack
	bool removeTop(E& returnValue) {
	
		// is list empty
		if (currSize == 0)
			return false;

		else 
		{
			returnValue = stackArray[--currSize]; // remove top

			// is list empty
			if (currSize == 0)
				return false;
			else
				return true;
		}
		
	
	}

	// search stack for item
	bool find(E& returnValue) const {
	
		// traverse the stack
		for (int j = 0; j < currSize; j++)
		{
			// if item is found at current position
			if (stackArray[j] == returnValue)
			{
				// update
				returnValue = stackArray[j];

				return true;
			}
	
		}

		return false;
	}

	bool inspectTop(E& item) const {
	
		// if bag is empty return false
		if (currSize == 0)
			return false;
		else
		{
			// update item with content of bag
			item = stackArray[currSize - 1];

			return true; // bag is not empty
		}
	
	}

	// clear the bag
	void emptyBag() {
		
		//logical "clear" as it will just overwrite new values with old ones
		currSize = 0;
		
	}

	// overwrite the += operator to add
	bool operator+=(const E& addend) { return addItem(addend); }

	// returns current number of elements in stack
	int size() const { return currSize; }

	// returns max number of potenial elements in the stack
	int bagCapacity() const { return capacity; }

	//Returns the top value of the bag
	E peek() const { return stackArray[currSize-1]; }

};


#include <string>
#include <fstream>
#include <iostream>

typedef float Element;

class DynamicArray{

	private:
		//Array of elements, since the array has to be dynamic
		//this value is a pointer to an Element
		Element* dynamicArray;

		//The number of elements currently in the array
		int arraySize;

		//The number of elements that can possibly fit in the array without reallocation
		int arrayCapacity;

	public:
		//Default Constructor
		DynamicArray();
		
		//Explicit Value Constructor
		DynamicArray(int size, Element e);
		
		//Destructor
		~DynamicArray();

		//Add to end
		void push_back(Element e);
		
		//Remove from end and return
		Element pop_back();
		
		//Search, return position in array, -1 if not found
		int search(Element e);

		//Indicate whether or not the provided index is valid
		bool valid_index(int index);

		//Return the size of the array (number of elements currently in the array)
		int size();

		//Return the capacity of the array (number of elements the array can currently hold)
		int capacity();
};

/*
Remember to combine into a single file when you're done
*/

/*

TO-DO:

-Mind out of bounds and array = full
-Create function in main: loop using get() to print
-need to put get_position in there
-data validation should be changed into a main function, too much repeated use


*/

#include <iostream>

using namespace std;

template <class FILLERWORD> class sequence {
	int capacity; //hold array cap.
	int num_used;
	FILLERWORD *array_p;

public:
	//Constructor
	sequence();
	sequence(int size);

	//Destructor
	~sequence();

	bool full();
	bool empty();
	int get_capacity();
	int get_num_used();
	FILLERWORD get(int userInput);
		//POST: Return value at given position
	void set(int userInput_position, FILLERWORD userInput_entry);
		//POST: Set value at given position
	void add_element(FILLERWORD userInput);
		//POST: Add given element to next available position
	int get_position(FILLERWORD userInput);


};

template <class FILLERWORD>
sequence<FILLERWORD>::sequence()
	:num_used(0), capacity(10) {
	array_p = new FILLERWORD[capacity];
}

template <class FILLERWORD>
sequence<FILLERWORD>::sequence(int size) 
	:num_used(0), capacity(size) {
	array_p = new int[capacity];
}

template <class FILLERWORD>
sequence<FILLERWORD>::~sequence() {
	delete[] array_p;
}

template <class FILLERWORD>
bool sequence<FILLERWORD>::full() {
	return (num_used >= capacity);
}

template <class FILLERWORD>
bool sequence<FILLERWORD>::empty() {
	return (num_used == 0);
}

template <class FILLERWORD>
int sequence<FILLERWORD>::get_capacity() {
	return capacity;
}

template <class FILLERWORD>
int sequence<FILLERWORD>::get_num_used() {
	return num_used;
}

template <class FILLERWORD>
FILLERWORD sequence<FILLERWORD>::get(int userInput) {
	return array_p[userInput];
}

template <class FILLERWORD>
void sequence<FILLERWORD>::set(int userInput_position, FILLERWORD userInput_entry) {
	array_p[userInput_position] = userInput_entry;
}

template <class FILLERWORD>
void sequence<FILLERWORD>::add_element(FILLERWORD userInput) {
	if (!full()) {
		array_p[num_used] = userInput;
		num_used++;
	}
	else {
		cout << "ARRAY IS FULL. CANNOT ADD ANYMORE ELEMENTS." << endl;
	}
}
template <class FILLERWORD>
int sequence<FILLERWORD>::get_position(FILLERWORD userInput) {
	int i = 0;
	bool continueLoop = true;
	bool foundMatch = false;
	//Continue looping while foundMatch is false OR i is equal to num_used
	while (continueLoop)  {
		if (array_p[i] == userInput)
			foundMatch = true;
		else
			i++;

		//is foundMatch true? Then stop loop.
		//is i == num_used? Then stop loop.
		if (foundMatch || (i == num_used)) {
			continueLoop = false;
		}
	}
	if (i == num_used && (!foundMatch))
		return -1;
	else
		return i; //Fix number as for loop adds extra 1 to fall out of the loop
}

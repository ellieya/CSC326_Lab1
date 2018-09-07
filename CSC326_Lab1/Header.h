/*
Remember to combine into a single file when you're done
*/

/*

TO-DO:

-Mind out of bounds and array = full
-Create function in main: loop using get() to print

*/

#include <iostream>

using namespace std;

template <class FILLERWORD> class sequence {
	int capacity; //hold array cap.
	int num_used;
	int *array_p;

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
	void set(int userInput_position, FILLERWORD userInput_entry);
	void add_element(FILLERWORD userInput);
		//POST: Add given element to next available position
	int get_position(FILLERWORD userInput);


};

template <class FILLERWORD>
sequence<FILLERWORD>::sequence()
	:num_used(0), capacity(10) {
	array_p = new int[capacity];
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
	return (num_used < capacity)
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
	array_p[num_used] = userInput;
}
template <class FILLERWORD>
int sequence<FILLERWORD>::get_position(FILLERWORD userInput) {
	int i;
	bool foundMatch = false;
	for (i = 0; i < num_used; i++) {
		if array_p[i] == userInput
			foundMatch = true;
	}
	if (i = num_used && (!foundMatch))
		return -1;
	else
		return i;
}

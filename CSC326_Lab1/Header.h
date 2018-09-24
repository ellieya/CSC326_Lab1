/*
Remember to combine into a single file when you're done
*/

/*

TO-DO:
-Part A and Part B diff:
	add function and double_array. Check prototype in class delcaration as well as code.
-data validation should be changed into a main function, too much repeated use
-some more commenting, I feel this is very lacking
-Need to test that the 1 argument constructor is working
-output
-description
-extra credit: insert_element_at_given_position() and delete_element_at_given_position();


Check: Is OoB? Is Full?
-1) Add - OoB N/A , isFull done
-2) Get - OoB needs message, isFull N/A
-3) Set - OoB needs message, isFull N/A
	Add option to cancel
-4 - All N/A
-5 - N/A
-6 - N/A

Check OoB (index) should be in class
isFull should be in class
Data validation should also be in class because it relies on class value... :/

...ask the professor. Get and set usually aren't that complicated.

Checklist: https://dochub.com/ellienyaya/jB9j9W/pfalab1a-b-1

*/

#include <iostream>
#include <string>


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
	void double_array();
		//PRE: add_element() is used when full() is true
		//POST:  array_p's capacity is doubled and capacity * 2.
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
		cout << "SUCCESS!\n" << endl;
	}
	else {
		cout << "ARRAY IS FULL. CANNOT ADD ANYMORE ELEMENTS." << endl;
	}
	system("pause");
}

/*
FOR PART B

template <class FILLERWORD>
void sequence<FILLERWORD>::add_element(FILLERWORD userInput) {
	if (full()) {
		cout << "ARRAY IS FULL. Adding more room...";
		double_array();
		cout << "CAPACITY HAS BEEN EXTENDED TO " << capacity << "." << endl;
	}

	array_p[num_used] = userInput;
	num_used++;
	cout << "SUCCESS!\n" << endl;
	system("pause");

}

*/



template <class FILLERWORD>
void sequence<FILLERWORD>::double_array() {
	
	//Temporary pointer for new array
	FILLERWORD *holder = new FILLERWORD[capacity * 2];
	
	//Copy array_p into holder
	for (int i = 0; i < capacity; i++) {
		holder[i] = array_p[i];
	}

	array_p delete[];
	array_p = holder;
	capacity *= 2;

	//Holder should be automatically deallocated when this function is completed.
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

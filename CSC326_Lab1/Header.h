/*

TO-DO:
-extra credit: insert_element_at_given_position() and delete_element_at_given_position();
*/

#include <iostream>
#include <string>


using namespace std;

template <class item_type> class sequence {
	int capacity; //hold array cap.
	int num_used;
	item_type *array_p;

public:
	//Constructor
	sequence();
	sequence(int size);

	//Destructor
	~sequence();

	bool full();
	bool empty();
	bool is_OoB(int);
	int get_capacity();
	int get_num_used();
	item_type get(int userInput);
		//POST: Return value at given position
	void set(int userInput_position, item_type userInput_entry);
		//POST: Set value at given position
	void add_element(item_type userInput);
		//POST: Add given element to next available position
	void double_array();
		/*FOR PART B*/
		//PRE: add_element() is used when full() is true
		//POST:  array_p's capacity is doubled and capacity * 2.
	int get_position(item_type userInput);


};

template <class item_type>
sequence<item_type>::sequence()
	:num_used(0), capacity(10) {
	array_p = new item_type[capacity];

	//FOR TESTING PURPOSES ONLY DELETE AFTERWARDS!!!
	
	/*
	array_p[0] = 'A';
	array_p[1] = 'B';
	array_p[2] = 'C';
	array_p[3] = 'D';
	array_p[4] = 'E';
	array_p[5] = 'F';
	array_p[6] = 'G';
	array_p[7] = 'H';
	array_p[8] = 'I';
	array_p[9] = 'J';
	num_used = 10;
	*/
}

template <class item_type>
sequence<item_type>::sequence(int size) 
	:num_used(0), capacity(size) {
	array_p = new item_type[capacity];
}

template <class item_type>
sequence<item_type>::~sequence() {
	delete[] array_p;
}

template <class item_type>
bool sequence<item_type>::full() {
	return (num_used >= capacity);
}

template <class item_type>
bool sequence<item_type>::empty() {
	return (num_used == 0);
}

template <class item_type>
int sequence<item_type>::get_capacity() {
	return capacity;
}

template <class item_type>
int sequence<item_type>::get_num_used() {
	return num_used;
}

template <class item_type>
item_type sequence<item_type>::get(int userInput) {

	if (empty()) {
		throw 0;
	} else if (is_OoB(userInput)) {
		throw 1;
	} else {
		return array_p[userInput];
	}
}

template <class item_type>
void sequence<item_type>::set(int userInput_position, item_type userInput_entry) {
	
	if (empty()) {
		throw 0;
	}
	else if (is_OoB(userInput_position)) {
		throw 1;
	}
	else {
		array_p[userInput_position] = userInput_entry;
	}
}

template <class item_type>
void sequence<item_type>::add_element(item_type userInput) {

	/* FOR PART B */
	if (full()) {
		cout << "ARRAY IS FULL. Adding more room...\n";
		double_array();
		cout << "CAPACITY HAS BEEN EXTENDED TO " << capacity << "." << endl;
	}

	array_p[num_used] = userInput;
	num_used++;
	cout << "SUCCESS!\n" << endl;
	system("pause");

}


template <class item_type>
void sequence<item_type>::double_array() {
	
	//Temporary pointer for new array
	item_type *holder = new item_type[capacity * 2];
	
	//Copy array_p into holder
	for (int i = 0; i < capacity; i++) {
		holder[i] = array_p[i];
	}

	delete[] array_p;
	array_p = holder;
	capacity *= 2;

	//holder should be automatically deallocated when this function is completed.
}


template <class item_type>
int sequence<item_type>::get_position(item_type userInput) {
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


template <class item_type>
bool sequence<item_type>::is_OoB(int userInput) {
	return !(userInput >= 0 && userInput <= num_used - 1);
}
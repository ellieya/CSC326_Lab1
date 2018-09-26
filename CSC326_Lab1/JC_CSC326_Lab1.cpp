/*
Jiali Chen
Lab 1: Sequence Class
In Lab 1, we use a template class containing a dynamically allocated array.
The class contains functions to access private data members, get elements, to set elements, to search for elements, to add elements, etc.

*/

/* HEADER START */

#include <iostream>
#include <string>


using namespace std;

template <class item_type> class sequence {
	int capacity;
	int num_used;
	item_type *array_p;

public:
	//Constructor
	sequence();
	sequence(int size);

	//Destructor
	~sequence();

	bool full();
	//POST: Returns true if sequence is full. Returns false if sequence is not full.
	bool empty();
	//POST: Returns true if sequence is empty. Returns false if sequence is not empty.
	bool is_OoB(int);
	//PRE: Requires userInput
	//POST: Returns true if userInput is in the appropriate range for the function calling isOoB(). Otherwise, returns false.
	int get_capacity();
	//POST: Returns int capacity
	int get_num_used();
	//POST: Returns int num_used
	item_type get(int userInput);
	//PRE: Requires userInput
	//POST: Return the value at array_p[given index]
	void set(int userInput_position, item_type userInput_entry);
	//PRE: Requires 2 userInputs
	//POST: Set value at array_p[given index]
	void add_element(item_type userInput);
	//PRE: Requires userInput
	//POST: Add given element to next available position
	void double_array();
	/*FOR PART B*/
	//PRE: add_element() is used when full() is true
	//POST:  array_p's capacity is doubled and capacity * 2.
	int get_position(item_type userInput);
	//PRE: Requires userInput
	//Searches for value and returns the first index # found.
	//POST: Returns index # for requested value, or if not found, -1
	void insert_element(int, item_type);
	//PRE: Requires 2 userInputs
	//POST: Makes room, then inserts element at desired index.
	void delete_element(int);
	//PRE: Requires userInput
	//POST: Removes element at desired index and moves to occupy empty space.


};

/* HEADER END */

/* DRIVER START */

template <typename s> s prompt();
//Asks for user input and returns user input. Programmer must specify data type before use.
//Recommended not to use with string
//POST: Returns user input

int main() {

	sequence<char> charSeq;
	int userInput_menu = 1; //Must be initialized due to use of while loop
	int temp_int;
	char temp_char;

	while (userInput_menu != 0) {
		//Menu
		cout << "MENU\n"
			<< "1) Add new element\n" //cin & add
			<< "2) Get an element using index #\n" //get
			<< "3) Change data at selected position number\n" //set
			<< "4) Check sequence capacity\n" //test full/empty/get_capacity/get_num_used
			<< "5) Print contents of sequence\n"
			<< "6) Search for char\n"
			<< "7) Insert element at specific position\n"
			<< "8) Delete element at specific position\n"
			<< "0) Exit program\n\n"
			<< "SELECTION: ";
		cin >> userInput_menu;

		switch (userInput_menu) {
		case 1: //ADD
			system("CLS");

			cout << "ADDING ELEMENT" << endl;
			charSeq.add_element(prompt<char>());
			cout << "SUCCESS!\n" << endl;

			system("pause");
			system("CLS");
			break;

		case 2: //GET

			system("CLS");

			cout << "GETTING ELEMENT\n"
				<< "Please input an index number." << endl;

			temp_int = prompt<int>(); //Stored in variable for future printing
			try {
				temp_char = charSeq.get(temp_int); //Stored in variable for future printing
				cout << "The data in index #" << temp_int << " is \"" << temp_char << "\"" << endl;
			}
			catch (int exception) {
				switch (exception) {
				case 0: //EMPTY
					cout << "SEQUENCE IS EMPTY! Check sequence capacity before using GET ELEMENT!" << endl;
					break;
				case 1: //OOB
					cout << "INDEX IS OUT OF BOUNDS! Check sequence capacity before using GET ELEMENT!" << endl;
					break;
				}
			}

			system("pause");
			system("cls");

			break;

		case 3: //SET
			system("CLS");

			cout << "SETTING ELEMENT\n"
				<< "Please input an index number, followed by a char entry." << endl;

			try {
				/* Must be stored in temporary variables. If used in function, causes while loop to
				skip cin and therefore infinitely referring to case 3, unsure why */
				temp_int = prompt<int>();
				temp_char = prompt<char>();

				charSeq.set(temp_int, temp_char);
				cout << "SUCCESS!\n" << endl;
			}
			catch (int exception) {
				switch (exception) {
				case 0: //EMPTY
					cout << "SEQUENCE IS EMPTY! Check sequence capacity before using SET ELEMENT!" << endl;
					break;
				case 1: //OOB
					cout << "INDEX IS OUT OF BOUNDS! Check sequence capacity before using SET ELEMENT!" << endl;
					break;
				}
			}

			system("pause");
			system("CLS");

			break;

		case 4: //CHECK CAPACITY
			system("CLS");
			cout << "Is the sequence EMPTY or FULL?" << endl;
			if (charSeq.empty()) {
				cout << "Yes. The sequence is EMPTY." << endl;
			}
			else if (charSeq.full()) {
				cout << "Yes. The sequence is FULL." << endl;
			}
			else {
				cout << "No. The sequence is neither EMPTY nor FULL." << endl;
			}
			cout << "The sequence capacity is " << charSeq.get_capacity() << ".\n"
				<< "The sequence number used is " << charSeq.get_num_used() << ".\n" << endl;

			if (charSeq.empty()) {
				cout << "No indexes are avaliable for use. Please add a new element.\n" << endl;
			}
			else {
				cout << "Indexes 0 to " << charSeq.get_num_used() - 1 << " are avaliable for use.\n" << endl;
			}

			break;

		case 5: //PRINT

			system("CLS");
			if (charSeq.empty()) {
				cout << "SEQUENCE IS EMPTY!" << endl;
			}
			else {
				for (int i = 0; i < charSeq.get_num_used(); i++) {
					cout << "Entry at INDEX # " << i << " is \"" << charSeq.get(i) << "\"" << endl;
				}
			}
			system("pause");
			system("CLS");

			break;
		case 6: //SEARCH
			system("CLS");

			if (charSeq.empty()) {
				cout << "SEQUENCE IS EMPTY!" << endl;
			}
			else {

				cout << "Please input a char" << endl;
				temp_char = prompt<char>(); //Stored in temp for future use

				temp_int = charSeq.get_position(temp_char); //Results stored in temp_int to avoid running function twice
				if (temp_int == -1) {
					cout << "CHAR NOT FOUND!" << endl;
				}
				else {
					cout << "char FOUND AT INDEX " << temp_int << "!" << endl;
				}
			}
			system("pause");
			system("CLS");

			break;
		case 7: //INSERT ELEMENT
			system("CLS");

			cout << "INSERT ELEMENT\n"
				<< "Input an index in the first prompt, then a character in the second prompt.\n";

			temp_int = prompt<int>();
			temp_char = prompt<char>();

			try {
				charSeq.insert_element(temp_int, temp_char);
				cout << "SUCCESS!\n" << endl;
			}
			catch (logic_error) {
				cout << "INDEX IS OUT OF BOUNDS! Check sequence capacity before using INSERT ELEMENT!" << endl;
			}

			system("pause");
			system("CLS");
			break;
		case 8:
			system("CLS");

			cout << "DELETE ELEMENT\n"
				<< "Input an index.\n";

			temp_int = prompt<int>();

			try {
				charSeq.delete_element(temp_int);
				cout << "SUCCESS!\n" << endl;
			}
			catch (int exception) {
				switch (exception) {
				case 0: //EMPTY
					cout << "SEQUENCE IS EMPTY! Check sequence capacity before using DELETE ELEMENT!" << endl;
					break;
				case 1: //OOB
					cout << "INDEX IS OUT OF BOUNDS! Check sequence capacity before using DELETE ELEMENT!" << endl;
					break;
				}
			}

			system("pause");
			system("CLS");
			break;
		default:
			cout << "BAD INPUT!" << endl;
			return 1;
		}
	}

	return 0;
}

template <typename s>
s prompt() {
	s userInput;

	cout << "INPUT: ";
	cin >> userInput;

	return userInput;

}

/* DRIVER END */


/* IMPLEMENTATION START */

template <class item_type>
sequence<item_type>::sequence()
	:num_used(0), capacity(10) {
	array_p = new item_type[capacity];
}

template <class item_type>
sequence<item_type>::sequence(int size)
	: num_used(0), capacity(size) {
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

	//Throw error if empty() or is_OoB returns true, as get() cannot be used in those cases.
	if (empty()) {
		throw 0;
	}
	else if (is_OoB(userInput)) {
		throw 1;
	}
	else {
		return array_p[userInput];
	}
}

template <class item_type>
void sequence<item_type>::set(int userInput_position, item_type userInput_entry) {

	//Throw error if empty() or is_OoB returns true, as set() cannot be used in those cases.
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
	while (continueLoop) {
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


template <class item_type>
void sequence<item_type>::insert_element(int userInput_position, item_type userInput_entry) {

	//Check if out of bounds
	if (is_OoB(userInput_position)) {
		//If user selecting last number we can just use add_element() instead
		if (userInput_position == num_used)
			add_element(userInput_entry);
		//otherwise, throw error
		else
			throw logic_error("OOB");
	}
	else {
		//Change position until reach userInput_position
		for (int i = num_used; i > userInput_position; i--) {
			array_p[i] = array_p[i - 1];
		}

		//Make @ userInput_position equal to userInput_entry
		array_p[userInput_position] = userInput_entry;

		//Update num_used.
		num_used++;
	}

}

template <class item_type>
void sequence<item_type>::delete_element(int userInput) {
	if (empty()) {
		throw 0;
	}
	else if (is_OoB(userInput)) {
		throw 1;
	}
	else {
		//Change position of elements until reaches last element (num_used - 1)
		for (int i = userInput; i < (num_used - 1); i--) {
			array_p[userInput] = array_p[userInput + 1];
		}
	}

	/*
	NOTE THAT THE LAST ELEMENT WILL STILL HAVE LAST ELEMENT UNTIL add_element() REVISES IT
	*/

	//Update num_used
	num_used--;
}

/* IMPLEMENTATION END */



/*

* * * * * * * * * * * * * * * * * * * *
SAMPLE OUTPUT
* * * * * * * * * * * * * * * * * * * *

MENU
1) Add new element
2) Get an element using index #
3) Change data at selected position number
4) Check sequence capacity
5) Print contents of sequence
6) Search for char
7) Insert element at specific position
8) Delete element at specific position
0) Exit program

SELECTION:

* * * * * * * * * * * * * * * * * * * *

INSERT ELEMENT
Input an index in the first prompt, then a character in the second prompt.
INPUT: 9
INPUT: 1
INDEX IS OUT OF BOUNDS! Check sequence capacity before using INSERT ELEMENT!
Press any key to continue . . .

* * * * * * * * * * * * * * * * * * * *

DELETE ELEMENT
Input an index.
INPUT: 0
SEQUENCE IS EMPTY! Check sequence capacity before using DELETE ELEMENT!
Press any key to continue . . .

* * * * * * * * * * * * * * * * * * * *

Is the sequence EMPTY or FULL?
Yes. The sequence is EMPTY.
The sequence capacity is 10.
The sequence number used is 0.

No indexes are avaliable for use. Please add a new element.

MENU
1) Add new element
2) Get an element using index #
3) Change data at selected position number
4) Check sequence capacity
5) Print contents of sequence
6) Search for char
7) Insert element at specific position
8) Delete element at specific position
0) Exit program

SELECTION:

* * * * * * * * * * * * * * * * * * * *

ADDING ELEMENT
INPUT: 9
SUCCESS!

Press any key to continue . . .

* * * * * * * * * * * * * * * * * * * *

ADDING ELEMENT
INPUT: N
SUCCESS!

Press any key to continue . . .

* * * * * * * * * * * * * * * * * * * *

ADDING ELEMENT
INPUT: T
SUCCESS!

Press any key to continue . . .

* * * * * * * * * * * * * * * * * * * *

Entry at INDEX # 0 is "9"
Entry at INDEX # 1 is "N"
Entry at INDEX # 2 is "T"
Press any key to continue . . .

* * * * * * * * * * * * * * * * * * * *

INSERT ELEMENT
Input an index in the first prompt, then a character in the second prompt.
INPUT: 1
INPUT: U
SUCCESS!

Press any key to continue . . .


* * * * * * * * * * * * * * * * * * * *

Entry at INDEX # 0 is "9"
Entry at INDEX # 1 is "U"
Entry at INDEX # 2 is "N"
Entry at INDEX # 3 is "T"
Press any key to continue . . .

* * * * * * * * * * * * * * * * * * * *

Please input a char
INPUT: U
char FOUND AT INDEX 1!
Press any key to continue . . .

* * * * * * * * * * * * * * * * * * * *

DELETE ELEMENT
Input an index.
INPUT: 1
SUCCESS!

Press any key to continue . . .

* * * * * * * * * * * * * * * * * * * *

Entry at INDEX # 0 is "9"
Entry at INDEX # 1 is "N"
Entry at INDEX # 2 is "N"
Press any key to continue . . .

* * * * * * * * * * * * * * * * * * * *

GETTING ELEMENT
Please input an index number.
INPUT: 1
The data in index #1 is "N"
Press any key to continue . . .

* * * * * * * * * * * * * * * * * * * *

SETTING ELEMENT
Please input an index number, followed by a char entry.
INPUT: 1
INPUT: O
SUCCESS!

Press any key to continue . . .

* * * * * * * * * * * * * * * * * * * *

GETTING ELEMENT
Please input an index number.
INPUT: 1
The data in index #1 is "O"
Press any key to continue . . .

* * * * * * * * * * * * * * * * * * * *

Please input a char
INPUT: O
char FOUND AT INDEX 1!
Press any key to continue . . .

* * * * * * * * * * * * * * * * * * * *

Is the sequence EMPTY or FULL?
No. The sequence is neither EMPTY nor FULL.
The sequence capacity is 10.
The sequence number used is 3.

Indexes 0 to 2 are avaliable for use.

MENU
1) Add new element
2) Get an element using index #
3) Change data at selected position number
4) Check sequence capacity
5) Print contents of sequence
6) Search for char
7) Insert element at specific position
8) Delete element at specific position
0) Exit program

SELECTION:



*/
#include "Header.h"

template <typename s> s prompt();
//Asks for user input and returns user input. Programmer must specify data type before use.
//Recommended not to use with string
//POST: Returns user input

int main() {

	sequence<char> charSeq(5);
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
			<< "0) Exit program\n\n"
			<< "SELECTION: ";
		cin >> userInput_menu;

		switch (userInput_menu) {
		case 1: //ADD
			system("CLS");

			cout << "ADDING ELEMENT" << endl;
			charSeq.add_element(prompt<char>());
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

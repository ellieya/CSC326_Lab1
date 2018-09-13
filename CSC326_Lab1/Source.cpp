
/*
Remaining to-do:
-test to see no errors and shit
-output
-description
-some more commenting, I feel this is very lacking
*/



#include "Header.h"
#include <stdlib.h>
#include <string>

int main() {

	sequence<string> stringSeq;
	int userInput_menu = 1;
	string userInput_string;
	int userInput_int;

	while (userInput_menu != 0) {
		//Menu
		cout << "MENU\n"
			<< "1) Add new element\n" //cin & add
			<< "2) Get an element using index #\n" //get
			<< "3) Change data at selected position number\n" //set
			<< "4) Check sequence capacity\n" //test full/empty/get_capacity/get_num_used
			<< "5) Print contents of sequence\n"
			<< "0) Exit program\n\n"
			<< "SELECTION: ";
		cin >> userInput_menu;

		switch (userInput_menu) {
		case 1:
			system("CLS");
			cout << "ADDING ELEMENT\n" << "ENTER NEW ENTRY: ";
			cin >> userInput_string;
			stringSeq.add_element(userInput_string);
			system("CLS");
			cout << "SUCCESS!\n" << endl << flush;
			break;
		case 2:
			system("CLS");
			cout << "GETTING ELEMENT\n" << "ENTER INDEX#: ";
			cin >> userInput_int;
			cout << "The data in index #" << userInput_int << " is \"" << stringSeq.get(userInput_int) << "\"" << endl;
			system("pause");
			system("cls");
			break;
		case 3:
			system("CLS");
			if (stringSeq.get_num_used() == 0) {
				//Prevent setting any strings if there is no data present
				cout << "THERE ARE NO ITEMS IN STRINGSEQ. CANNOT RUN." << endl;
			}
			else {
				cout << "THERE ARE CURRENTLY " << stringSeq.get_num_used() << " OCCUPIED SLOTS IN THE SEQUENCE.\n"
					<< "Please select a number from 0 to " << stringSeq.get_num_used() << " for the index. \n" << endl;
				
				//Data validation for input
				 do {
					cout << "ENTER INDEX: ";
					cin >> userInput_int;
				 } while (!(userInput_int >= 0 && userInput_int <= stringSeq.get_num_used()));
			stringSeq.set(userInput_int, userInput_string);
			system("CLS");
			cout << "SUCCESS!\n" << endl << flush;
			}
			break;
		case 4:
			system("CLS");
			cout << "Is the sequence EMPTY or FULL?" << endl;
			if (stringSeq.full()) {
				cout << "Yes. The sequence is EMPTY." << endl;
			}
			else if (stringSeq.full()) {
				cout << "Yes. The sequence is FULL." << endl;
			}
			else {
				cout << "No. The sequence is neither EMPTY nor FULL." << endl;
			}
			cout << "The sequence capacity is " << stringSeq.get_capacity() << ".\n"
				<< "The sequence number used is " << stringSeq.get_num_used() << ".\n" << endl;
			break;
		case 5:
			system("CLS");
			for (int i = 0; i < stringSeq.get_num_used(); i++) {
				cout << "Entry at INDEX # " << i << " is \"" << stringSeq.get(i) << "\"" << endl;
			}
			if (stringSeq.get_num_used() == 0) {
				cout << "SEQUENCE IS EMPTY!" << endl;
			}
			break;
		default:
			cout << "BAD INPUT!" << endl;
			return 1;
		}
	}
	

	//print contents of a partially filled array after manips


	return 0;
}



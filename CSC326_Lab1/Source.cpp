#include "Header.h"

int main() {

	sequence<string> stringSeq;
	int userInput;

	//Menu
	cout << "MENU\n"
		<< "1) Add new element\n" //cin & add
		<< "2) Get element with position number\n" //get
		<< "3) Change data at selected position number\n" //set
		<< "4) Check sequence capacity\n" //test full/empty/get_capacity/get_num_used
		<< "5) Print contents of sequence\n\n"
		<< "SELECTION: ";
	cin >> userInput;

	switch (userInput) {
	case 1:
		
		//PUT THE CLEAR THING
		stringSeq.add_element();
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	default:
		cout << "BAD INPUT!" << endl;
		return 1;
	}
	

	//print contents of a partially filled array after manips


	return 0;
}



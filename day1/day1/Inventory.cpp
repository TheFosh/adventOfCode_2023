//Jake Swanson 1.2: Inventory implementation
/*
* Implents methods of Inventory header.
*/

#include "Inventory.h"

Inventory::Inventory() { //Default Constructor
	data = new string[CAPACITY];
	totalAnswer = 0;
	index = 0;
}


// Method that given a file name will read the file and fill the string array data.
// Will return true or false depanding on if the file opens.
bool Inventory::getData(string _fileName_) { 

	fstream inFile;
	inFile.open(_fileName_);

	if (inFile.fail()) return false;

	for (int i = 0; i < CAPACITY; ++i) 
	{
		getline(inFile, data[i]);
	}

	return true;
}


// Main method that reads data in array.
// Gives lines of data array to protected methods, getFirstNum and getLastNum.
// These two functions give the digits for the number of each line.
// Returns the total of all lines added together.
void Inventory::getTotal() {
	for (int i = 0; i < CAPACITY; ++i) {
		string currLine = data[i];

		totalAnswer += (10 * getFirstNum(currLine) + getLastNum(currLine));
	}
}


//Returns first number found in given string
int Inventory::getFirstNum(string _line_) {
	int firstNum;
	char tmpChar;
	
	for (int i = 0; i < _line_.size(); ++i) {

		//CHANGE FOR PART 2

		tmpChar = _line_[i];

		if (tmpChar >= '0' && tmpChar <= '9') {
			firstNum = tmpChar - '0';
			index = i;
			return firstNum;
		}
	}

	return -1;
}

int Inventory::getLastNum(string _line_) {
	int firstNum = -1;
	char tmpChar;

	for (int i = index; i < _line_.size(); ++i) {

		firstNum = checkWord(_line_, i);
		if (firstNum != -1)
			return firstNum;

		tmpChar = _line_[i];
		if (tmpChar >= '0' && tmpChar <= '9') {
			firstNum = tmpChar - '0';
		}
	}

	return firstNum;
}


//NEW METHOD FOR PART 2
int Inventory::checkWord(string _line_, int index) {
	return -1;
}

void Inventory::printData() {
	for (int i = 0; i < CAPACITY; ++i) {
		cout << data[i] << endl;
	}
}
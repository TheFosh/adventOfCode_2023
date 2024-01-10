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

	inFile.close();

	return true;
}


// Main method that reads data in array.
// Gives lines of data array to protected methods, getFirstNum and getLastNum.
// These two functions give the digits for the number of each line.
// Returns the total of all lines added together.
void Inventory::getTotal() {
	for (int i = 0; i < CAPACITY; ++i) {
		string currLine = data[i];
		//cout << "Line: " << i +1 << endl;
	  	//cout << getFirstNum(currLine) << endl;
		//cout << getLastNum(currLine) << endl;

		totalAnswer += (10 * getFirstNum(currLine) + getLastNum(currLine));
	}
}


//Returns first number found in given string
int Inventory::getFirstNum(string _line_) {
	int firstNum;
	char tmpChar;
	
	for (int i = 0; i < _line_.size(); ++i) {

		tmpChar = _line_[i];

		// Checks if current char is in the range 0-9.
		// If yes, it converts it to an int.
		// Returns the number if so
		if (tmpChar >= '0' && tmpChar <= '9') {
			firstNum = tmpChar - '0';
			index = i; // Sets the index of first to help checking the next digit.
			return firstNum;
		}

		//CHANGE FOR PART 2
		for (int w = 0; w < wordSize; ++w) {
			if (_line_.find(numWords[w]) == i) {
				index = i;
				return w;
			}
		}
	}

	return -1;
}

int Inventory::getLastNum(string _line_) {

	int firstNum = -1;
	char tmpChar;

	for (int i = index; i < _line_.size(); ++i) {
		// Checks if current char is in the range 0-9.
		// If yes, it converts it to an int.
		tmpChar = _line_[i];
		if (tmpChar >= '0' && tmpChar <= '9') {
			firstNum = tmpChar - '0';
		}

		// PART 2
		for (int w = 0; w < wordSize; ++w) {
			if (_line_.rfind(numWords[w]) == i) {
				firstNum = w;
			}
		}
	}

	return firstNum;
}


// Prints all lines in puzzle data
void Inventory::printData() {
	for (int i = 0; i < CAPACITY; ++i) {
		cout << data[i] << endl;
	}
}
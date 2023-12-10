//Jake Swanson 1.1: Inventory implementation

#include "Inventory_p1.h"

Inventory::Inventory() {
	data = new string[CAPACITY];
	totalAnswer = 0;
	index = 0;
}

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

void Inventory::getTotal() {
	for (int i = 0; i < CAPACITY; ++i) {
		string currLine = data[i];

		totalAnswer += (10 * getFirstNum(currLine) + getLastNum(currLine));
	}
}

int Inventory::getFirstNum(string _line_) {
	int firstNum;
	char tmpChar;
	
	for (int i = 0; i < _line_.size(); ++i) {
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
		tmpChar = _line_[i];

		if (tmpChar >= '0' && tmpChar <= '9') {
			firstNum = tmpChar - '0';
		}
	}

	return firstNum;
}

void Inventory::printData() {
	for (int i = 0; i < CAPACITY; ++i) {
		cout << data[i] << endl;
	}
}
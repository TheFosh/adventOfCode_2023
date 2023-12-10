#include "Inventory_p1.h"

Inventory::Inventory() {
	data = new string[CAPACITY];
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

void Inventory::printData() {
	for (int i = 0; i < CAPACITY; ++i) {
		cout << data[i] << endl;
	}
}
#include "Inventory.h"
#include <fstream>
#include <iostream>
#include <string>

Inventory::Inventory(string fileName) {
	fstream inFile;

	try {
		inFile.open(fileName);

		if (inFile.fail()) throw exception("File not found.");
	}
	catch (exception e) {
		cout << e.what() << endl;
		exit(1);
	}

	string currentLine;

	while (getline(inFile, currentLine)) {
		Card currentCard(currentLine);

		cardData.push_back(currentCard);
	}

	inFile.close();
}
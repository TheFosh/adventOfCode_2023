// Jake Swanson: Advent of code 2023 - day 4
// Implementation file for Inventory object

#include "Inventory.h"
#include <fstream>
#include <iostream>
#include <string>

Inventory::Inventory(string fileName) {
	fstream inFile;

	try {// Trys to open file given
		inFile.open(fileName);

		if (inFile.fail()) throw exception("File not found.");
	}
	catch (exception e) {// Throws exception if it fails
		cout << e.what() << endl;
		exit(1);
	}
	// When successful

	//Using a place holder variable, each line is read in the file and is sent to create a new card object
	string currentLine;
	while (getline(inFile, currentLine)) {
		Card currentCard(currentLine);

		// The new card is then added to the inventory's list
		cardData.push_back(currentCard);
	}

	inFile.close();
}

int Inventory::calScore() {

}
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
	int count = 1;
	while (getline(inFile, currentLine)) {
		Card currentCard(count, currentLine);

		// The new card is then added to the inventory's list
		cardData.push_back(currentCard);

		++count;
	}

	inFile.close();
}

int Inventory::calScore() {
	int total = 0;

	// Goes through all cards
	for (Card c : cardData) 
	{
		// Gets the count of winning pairs for each
		int count = c.countPairs();

		// If there is at least	1 pair then a score is calculated and added to the total
		if (count >= 1) 
		{
			int score = pow(2, count -1);

			total += score;
		}
	}

	return total;
}

int Inventory::countWinningCards() {
	int total = 0;

	list<Card>::iterator itr = cardData.begin();

	//for (int i = 0; i < cardData.size() -4; ++i)
	//{
	//	++itr;
	//}

	// Goes through all cards
	for (itr; itr != cardData.end(); ++itr)
	{
		// If there is at least	1 pair then a score is calculated and added to the total
		if((*itr).countPairs() > 0)
			total += recursiveCounting(itr, 0) + 1;
	}

	return total;
}

int Inventory::recursiveCounting(list<Card>::iterator itr, int total) {

	int count = (*itr).countPairs();

	for (int i = 0; i < count; ++i) {
		++itr;
		total = recursiveCounting(itr, ++total);
	}

	return total;
}
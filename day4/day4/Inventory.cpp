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

	// Goes through all cards
	for (itr; itr != cardData.end(); ++itr)
	{
		// If there is at least	1 pair then a score is calculated and added to the total
		if((*itr).countPairs() > 0)
			total += recursiveCounting(itr, 0);
		++total;// Counts every card
	}

	return total;
}

/*
* Given an iterator pointing towards a card, the count of it's winning numbers determines how
* many copies are made of the the next cards after it. All these copies are then resent to this method to count
* and check how many copies each one of those make.
*/
int Inventory::recursiveCounting(list<Card>::iterator itr, int total) {

	int count = (*itr).countPairs();// Count of current card

	// Goes through each iterator after the current one based on the count above
	for (int i = 0; i < count; ++i) {
		++itr;

		// Sets the total count to the number of times this method is recursevly called
		// This in effect counts the number of copies of a card
		total = recursiveCounting(itr, ++total);
	}

	// When all copies have been looked through and counted, the total of that counting is returned
	return total;
}
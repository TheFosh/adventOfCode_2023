//Jake Swanson: Advent of Code 2023 - Day 4
// Inventory object header file
/*
* This object stores the card objects for the puzzle in a neat list.
* Used to manipulate the data and read the contents easily.
*/

#include "Card.h"
#include <list>

#ifndef I_H
#define I_H

class Inventory {
public:
	Inventory(string);// Given a string for an input file, an inventory object is constructed
	int calScore();// Gets the score of all cards in the inventory list and returns the added total
	///PART 2///
	int countWinningCards();// Gets the number of cards that won

	list<Card> getData() { return cardData; }// Getter for card list

protected:
	int recursiveCounting(list<Card>::iterator, int);// Recursivly counts how many times a card of the given iterator is copied

private:
	list<Card> cardData;
};

#endif // !I_H

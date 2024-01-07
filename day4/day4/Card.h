// Jake Swanson: Advent of Code 2023 - Day 4
// Card object header file
/*
* For the puzzle, there are "cards" that contain a set of winning numbers
* and numbers you have. This object is ment to hold this information.
*/

using namespace std;
#include <string>

#ifndef C_H
#define C_H

class Card {
public:
	Card(string);// Given the line of text, a card object is constructed
	Card(const Card&);// Copy constructor

	// Getters for the arrays
	int* getNums() { return nums; }
	int* getWinners() { return winners; }

protected:
	void sortWinners();// Sorts the winners array

private:
	int* nums;// Pointer to an array of your numbers
	int* winners;// Pointer to an array of the winning numbers
};

#endif // !C_H


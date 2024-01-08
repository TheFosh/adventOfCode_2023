// Jake Swanson: Advent of Code 2023 - Day 4
// Card object header file
/*
* For the puzzle, there are "cards" that contain a set of winning numbers
* and numbers you have. This object is ment to hold this information.
*/

using namespace std;
#include <string>
#include <algorithm>

#ifndef C_H
#define C_H

class Card {
public:
	Card(string);// Given the line of text, a card object is constructed

	// Getters for the arrays
	int* getNums() { return nums; }
	int* getWinners() { return winners; }

	friend const ostream& operator<<(const ostream&, const Card&);// Used for printing out card contents

private:
	const int NUM_CAPACITY = 25;
	const int WINNER_CAPACITY = 10;

	int nums[25];// Pointer to an array of your numbers
	int winners[10];// Pointer to an array of the winning numbers
};

#endif // !C_H


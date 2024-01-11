// Jake Swanson: Advent of Code 2023 - Day 4
// Main runner file

#include "Inventory.h"
#include <iostream>

int main() {

	// Input file name
	string fileName = "input.txt";

	// Object to hold the information
	Inventory inv(fileName);

	// See the result
	//cout << inv.calScore() << endl;// My answer - 20667
	cout << inv.countWinningCards() << endl;// My Answer - 5833065
}
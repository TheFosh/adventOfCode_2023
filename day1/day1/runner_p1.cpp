//Jake Swanson 1.1: runner_p1 day1_part1
/*
* Part 1
* Given a puzzle input of lines of text,
* there are numbers in each line.
* Find the first and last digit to form a 2 digit number.
* Combine all the numbers together to get the solution to the puzzle.
*/

#include "Inventory_p1.h"

int main() {

	Inventory inv;
	string fileName = "input.txt";

	try {
		if (!inv.getData(fileName)) throw exception("Could not open file");
	}
	catch (exception e) {
		cerr << e.what() << endl;
	}

	inv.printData();

	return 0;
}
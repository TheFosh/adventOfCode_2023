//Jake Swanson 1.2: runner file
/*
* Part 1
* Given a puzzle input of lines of text,
* there are numbers in each line.
* Find the first and last digit to form a 2 digit number.
* Part 2
* The numbers include words of numbers (e.i. "one", "two", ...)
* Combine all the numbers together to get the solution to the puzzle.
*/

#include "Inventory.h"

int main() {

	Inventory inv;
	string fileName = "input.txt";

	try {
		if (!inv.getData(fileName)) throw exception("Could not open file");
	}
	catch (exception e) {
		cerr << e.what() << endl;
	}

	//inv.getTotal();

	cout << inv.viewTotal(); //Answer printed: 54331

	return 0;
}
//Jake Swanson 1.1: day1_part1
/*
* Part 1
* Given a puzzle input of lines of text,
* there are numbers in each line.
* Find the first and last digit to form a 2 digit number.
* Combine all the numbers together to get the solution to the puzzle.
*/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
	fstream inFile;

	try {
		inFile.open("input.txt");
		if (inFile.fail()) throw exception("Could not open file");
	}
	catch (exception e) {
		cerr << e.what() << endl;
	}

	return 0;
}
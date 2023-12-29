#include "Board.h"
#include <fstream>

Board::Board(string fileName)
{
	fstream inFile;

	try {
		inFile.open(fileName);

		if (inFile.fail()) throw exception("File not found");
	}
	catch (exception e) {
		cout << e.what() << endl;
		exit(1);
	}
	
	string tmpLine;

	inFile >> tmpLine;

	int numberOfRows;
	int numberOfColumns = tmpLine.size();

	while () {

	}

	allData = new char[1][1];
}
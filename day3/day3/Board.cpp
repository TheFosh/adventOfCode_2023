#include "Board.h"
#include <fstream>

Board::Board(string fileName)
{
	fstream inFile;

	try {
		// Trys to open file
		inFile.open(fileName);

		if (inFile.fail()) throw exception("File not found");
	}
	catch (exception e) {
		cout << e.what() << endl;
		exit(1);
	}
	
	string tmpLine;

	//Adds contents of file to the board's 2D array
	int rowCount = 0;
	while (inFile >> tmpLine) {

		for (int col = 0; col < tmpLine.size(); ++col)
		{
			allData[rowCount][col] = tmpLine[col];
		}

		++rowCount;
	}
}

// Gets answer to puzzle
int Board::getTotal() {
	int total = 0;

	for(int row = 0; row < ROWS; ++row)
	{
		for (int col = 0; col < COLUMNS; ++col)
		{

			// Checks if the char checked is a number
			// Then checks if there is a symbol around it
			if (isNum(row, col) && checkIfSymbolAround(row, col))
			{
				// If both are true, the number is added to the total
				
				int validNum = createNum(0, row, col);

				//cout << "Valid num: " << validNum << endl;

				total += validNum;

				// To skip rest of numbers
				col += getNumLength(validNum) - 1;
			}
		}
	}

	return total;
}

// Gets answer for specific symbols
int Board::getGearTotal() {
	int total = 0;

	for (int row = 0; row < ROWS; ++row)
	{
		for (int col = 0; col < COLUMNS; ++col)
		{
			if (allData[row][col] == '*' && countNumsAround(row, col) == 2)
			{
				total += getTotalAround(row, col);
			}
		}
	}

	return total;
}


// Returns whether the char in the board given is a number
bool Board::isNum(int row, int col)
{
	return (allData[row][col] - '0' >= 0) && ('9' - allData[row][col] >= 0);
}

// Checks around the given poistion in 2D array to see if a symbol is around using recerison
bool Board::checkIfSymbolAround(int row, int col)
{

	bool checkUp = row - 1 != -1;
	bool checkDown = row + 1 != ROWS;

	bool checkLeft = col - 1 != -1;
	bool checkRight = col + 1 != COLUMNS;

	// Could not find an easier way to check all eight spots around given point
	// Will look into possible ways

	/*Top left*/ 
	if ((checkUp && checkLeft) && (allData[row - 1][col - 1] != '.' && !isNum(row - 1, col - 1)))
		return true;
	/*Top*/
	if ((checkUp) && (allData[row - 1][col] != '.' && !isNum(row - 1, col)))
		return true;
	/*Top Right*/
	if ((checkUp && checkRight) && (allData[row - 1][col + 1] != '.' && !isNum(row - 1, col + 1)))
		return true;
	/*Left*/
	if ((checkLeft) && (allData[row][col - 1] != '.' && !isNum(row, col - 1)))
		return true;
	/*Right*/
	if ((checkRight) && (allData[row][col + 1] != '.' && !isNum(row, col + 1)))
		return true;
	/*Bottom Left*/
	if ((checkDown && checkLeft) && (allData[row + 1][col - 1] != '.' && !isNum(row + 1, col - 1)))
		return true;
	/*Bottom*/
	if ((checkDown) && (allData[row + 1][col] != '.' && !isNum(row + 1, col)))
		return true;
	/*Bottom Right*/
	if ((checkDown && checkRight) && (allData[row + 1][col + 1] != '.' && !isNum(row + 1, col + 1)))
		return true;

	if (col + 1 != COLUMNS && isNum(row, col + 1))
		return checkIfSymbolAround(row, col + 1);

	return false;
}

// Creates a number based on the given position recurcively
int Board::createNum(int num, int row, int col) {

	int tempNum = allData[row][col] - '0';

	num += tempNum;

	if (col + 1 != COLUMNS && isNum(row, col + 1))
		return createNum(num * 10, row, col + 1);

	return num;
}

// Gets the number of digits in the number given
// Finds this recurcively
int Board::getNumLength(int num) {

	if (num >= 10)
		return 1 + getNumLength(num / 10);

	return 1;
}

// Prints out contents of 2D array
void Board::printBoard(){
	for (int row = 0; row < ROWS; ++row)
	{
		for (int col = 0; col < COLUMNS; ++col)
		{
			cout << allData[row][col];
		}
		cout << endl;
	}
}
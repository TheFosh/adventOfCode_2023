// Jake Swanson:
// Inventory object implementation

#include "Inventory.h"
#include <sstream>

Inventory::Inventory(string fileName) {

	fstream inFile;

	try 
	{
		inFile.open(fileName);
		if (inFile.fail())
			throw exception("File could not be read.");
	}
	catch (exception e) 
	{
		cout << e.what() << endl;
		exit(1);
	}

	string lineHolder; // Holds the line of each game

	// Loops until all lines are read
	while (getline(inFile, lineHolder)) 
	{
		// Cuts line down to the first number for a color
		lineHolder = lineHolder.substr(lineHolder.find_first_of(':') +2);

		data.push_back(makeGame(lineHolder));
	}

	inFile.close();
}


Game Inventory::makeGame(string line)
{
	int* rArrayHolder = new int[3];
	int* bArrayHolder = new int[3];
	int* gArrayHolder = new int[3];

	// Loops until there are no semi colans found
	while (line.find_first_of(';') != -1)
	{
		string currentGame = line.substr(0, line.find_first_of(';'));
		line = line.substr(line.find_first_of(';') + 2);

		int redHolder;
		int blueHolder;
		int greenHolder;

		stringstream words(currentGame);

		int currNum;
		string currColor;

		words >> currNum;
		words >> currColor;

		cout << currNum << endl;
		cout << currColor << endl;

		/*while (currentGame != "")
		{
			int currNumber;
			string currColor;



		}*/

		//words >> currNumber;

	}
}

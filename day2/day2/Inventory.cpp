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
	int arraySize = countSemiColan(line) + 1;

	int* rArrayHolder = new int[arraySize];
	int* bArrayHolder = new int[arraySize];
	int* gArrayHolder = new int[arraySize];

	//For finding index of in color array
	int arrayCount = 0;

	// Loops until there are no semi colans found
	while (line.find_first_of(';') != -1)
	{
		string currentGame = line.substr(0, line.find_first_of(';'));
		line = line.substr(line.find_first_of(';') + 2);

		stringstream words(currentGame);

		int currNum;
		string currColor;

		while (!words.fail())
		{
			words >> currNum;
			words >> currColor;

			if (currColor.find_first_of(',') != -1)
				currColor = currColor.substr(0, currColor.find_first_of(','));

			if (currColor == "red")
				rArrayHolder[arrayCount] = currNum;

			else if (currColor == "blue")
				bArrayHolder[arrayCount] = currNum;

			else if (currColor == "green")
				gArrayHolder[arrayCount] = currNum;
			
		}

		arrayCount++;
		//words >> currNumber;
	}

	cout << line << endl;

	return Game(arraySize, rArrayHolder, bArrayHolder, gArrayHolder);
}

int Inventory::countSemiColan(string line) {
	int count = 0;

	for (int i = 0; i < line.size(); ++i)
	{
		if (line[i] == ';')
			++count;
	}

	return count;
}
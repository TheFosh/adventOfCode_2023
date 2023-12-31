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

list<Game> Inventory::getMinSet() {
	list<Game> myList;

	list<Game>::iterator itr = data.begin();
	for (itr; itr != data.end(); ++itr)
	{
		Game g = *itr;

		int redMax = 0;
		int blueMax = 0;
		int greenMax = 0;

		int* currReds = g.getReds();
		int* currBlues = g.getBlues();
		int* currGreens = g.getGreens();

		for (int i = 0; i < g.getSize(); ++i)
		{
			if (currReds[i] > redMax)
				redMax = currReds[i];
			if (currBlues[i] > blueMax)
				blueMax = currBlues[i];
			if (currGreens[i] > greenMax)
				greenMax = currGreens[i];
		}
		int size = 1;

		Game tempGame(size, &redMax, &blueMax, &greenMax);
		myList.push_back(tempGame);
	}

	return myList;
}


Game Inventory::makeGame(string line)
{
	int arraySize = countSemiColan(line) + 1;

	//Sets each array to be the temp array
	int* rArrayHolder = new int[arraySize];
	int* bArrayHolder = new int[arraySize];
	int* gArrayHolder = new int[arraySize];

	// Fill arrays with zeros
	for (int i = 0; i < arraySize; ++i) {
		rArrayHolder[i] = bArrayHolder[i] = gArrayHolder[i] = 0;
	}

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

	stringstream words(line);

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

void Inventory::printInventory() {
	int count = 1;

	list<Game>::iterator itr = data.begin();
	for (itr; itr != data.end(); ++itr)
	{
		cout << "Game " << count << ":" << endl;
		cout << *itr << endl;

		count++;
	}
}

int Inventory::solvePuzzle(int* solution) {
	int total = 0;

	int count = 1;
	
	cout << solution[0] << solution[1] << solution[2] << endl;

	list<Game>::iterator itr = data.begin();
	for (itr; itr != data.end(); ++itr)
	{

		Game g = *itr;
		//cout << "current game: " << count << endl;

		bool check = true;

		int* red = g.getReds();
		int* blue = g.getBlues();
		int* green = g.getGreens();

		for (int i = 0; i < g.getSize(); ++i)
		{	
			/*
			cout << "red: " << red[i] << endl;
			cout << "blue: " << blue[i] << endl;
			cout << "green: " << green[i] << endl;
			*/

			if (red[i] > solution[0] || blue[i] > solution[1] || green[i] > solution[2])
				check = false;
		}

		if (check)
			total += count;

		++count;
	}

	return total;
}
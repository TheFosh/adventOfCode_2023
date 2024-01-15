// Jake Swanson: Advent of code 2023
// Inventory implementation file

#include "Inventory.h"
#include <fstream>
#include <iostream>
#include <sstream>

Inventory::Inventory(string fileName) {
	fstream inFile;

	try {
		inFile.open(fileName);
		if (inFile.fail()) throw exception("File not found.");
	}
	catch (exception e) {
		cout << e.what() << endl;
		exit(1);
	}

	// Reading data for seed list
	{
		string seedData;
		getline(inFile, seedData);

		stringstream allNums(seedData);
		string currentWord;

		allNums >> currentWord;

		while (allNums >> currentWord)
		{
			long long num = stoll(currentWord);
			seeds.push_back(num);
		}
	}

	// Reading data for almanac
	{
		inFile.ignore(1000, '\n');

		string almanacData;
		string currentLine;
		while (getline(inFile, currentLine))
			almanacData += currentLine + "\n";

		theMappings = *new Almanac(almanacData);
	}

	inFile.close();
}

list<long long> Inventory::getLocations() {
	
	list<long long> answerData;
	
	// Goes through list of seeds and sends each one to be converted to a location
	for (list<long long>::iterator itr = seeds.begin(); itr != seeds.end(); ++itr)
	{
		// Answers are saved
		answerData.push_back(theMappings.getLocation(*itr));
	}

	return answerData;
}
// Jake Swanson:
// Inventory object implementation

#include "Inventory.h"

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

	string lineHolder;

	while (getline(inFile, lineHolder)) {

	}

	inFile.close();
}
// Jake Swanson: Advent of Code 2023
// Main runner file

#include "Inventory.h"
#include <iostream>

using namespace std;

int findMin(list<int>);

int main() {

/*	string fileContent = readFile("input.txt");

	Inventory myInventory(fileContent);

	cout << findMin(myInventory.getLocations()) << endl;*/ 

	return 0;
}


// Function used to find the smallest of the all the locations in the given list
int findMin(list<int> loc) {
	list<int>::iterator itr = loc.begin();

	int min = *itr;

	for (++itr; itr != loc.end(); ++itr)
	{
		if (min > *itr)
			min = *itr;
	}

	return min;
}
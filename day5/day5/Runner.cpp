// Jake Swanson: Advent of Code 2023
// Main runner file

#include "Inventory.h"
#include <iostream>

using namespace std;

long long findMin(list<long long>);

int main() {
	Inventory myInventory("input.txt");

	//cout << findMin(myInventory.getLocations()) << endl;

	return 0;
}


// Function used to find the smallest of the all the locations in the given list
long long findMin(list<long long> loc) {
	list <long long> ::iterator itr = loc.begin();

	int min = *itr;

	for (++itr; itr != loc.end(); ++itr)
	{
		if (min > *itr)
			min = *itr;
	}

	return min;
}
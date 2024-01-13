// Jake Swanson: Advent of code 2023
// Inventory header file (I was wrong. I'm not tired of it)

#include "Almanac.h"

#ifndef I_H
#define I_H

class Inventory {
public:
	Inventory(string);// Constructor

	list<int> getLocations();// Get answer to puzzle and maps all seeds to locations and returns a list of them

private:
	list<int> seeds;
	Almanac theMappings;
};

#endif // !I_H

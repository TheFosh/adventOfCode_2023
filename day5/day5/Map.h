// Jake Swanson: Advent of Code 2023
// Map object header
/*
* Object used to describe a range of where a number can fall into
* and where it will be mapped to.
*/

using namespace std;

#include <string>

#ifndef M_H
#define M_H

class Mapping {
public:
	Mapping(string);

	// Getters for the private members
	long long getDestination() { return destination; }
	long long getSource() { return source; }
	long long getRange() { return range; }

	bool withinSourceRange(long);// Checks if the given num is within the source range

	// ASSUMED: The number provied is within the source range
	long newDestination(long);// Given a num, the mapping of the new destination is returned

private:
	long long destination;
	long long source;
	long long range;
};

#endif // !M_H

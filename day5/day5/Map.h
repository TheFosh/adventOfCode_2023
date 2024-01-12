// Jake Swanson: Advent of Code 2023
// Map object header
/*
* Object used to describe a range of where a number can fall into
* and where it will be mapped to.
*/

#ifndef M_H
#define M_H

class Mapping {
public:
	// Getters for the private members
	int getDestination() { return destination; }
	int getSource() { return source; }
	int getRange() { return range; }

	bool withinSourceRange(int);// Checks if the given num is within the source range

	// ASSUMED: The number provied is within the source range
	int newDestination(int);// Given a num, the mapping of the new destination is returned

private:
	int destination;
	int source;
	int range;
};

#endif // !M_H

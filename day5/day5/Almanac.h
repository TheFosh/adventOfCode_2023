// Jake Swanson: Advent of Code 2023
// Almanac header file (got tired of inventory and this relate more to the puzzle)
/*
* Object contains all mappings for solving puzzle.
*/

#include "Map.h"
#include <list>

#ifndef A_H
#define A_H

class Almanac {
public:
	Almanac(){};// Default constructor
	Almanac(string);

	long long getLocation(long long);// Given a num for a seed, a location that corresponds to all the mappings is returned

	list<Mapping> getToSoil() { return toSoil; }
	list<Mapping> getToFerterlizer() { return toFerterlizer; }
	list<Mapping> getToWater() { return toWater; }
	list<Mapping> getToLight() { return toLight; }
	list<Mapping> getToTemp() { return toTemp; }
	list<Mapping> getToHumidity() { return toHumidity; }
	list<Mapping> getToLocation() { return toLocation; }

protected:
	list<Mapping> makeList(string);// Makes a list of mappings based on the string given to it
	Mapping checkList(list<Mapping>, int);// Given a list and a number, the list is checked through to see if the number is in any of the mappings

private:
	list<Mapping> toSoil;
	list<Mapping> toFerterlizer;
	list<Mapping> toWater;
	list<Mapping> toLight;
	list<Mapping> toTemp;
	list<Mapping> toHumidity;
	list<Mapping> toLocation;
};

#endif // !A_H

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
	Almanac(string);

	int getLocation(int);// Given a num for a seed, a location that corresponds to all the mappings is returned

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

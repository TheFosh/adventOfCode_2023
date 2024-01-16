// Jake Swanson: Advent of code 2023
// Mapping implementatuion file

#include "Map.h"

// Given a string three numbers are extracted set to their respective variables
Mapping::Mapping(string line) {
	string currentNum = line.substr(0, line.find(' '));
	line = line.substr(line.find(' ') +1);

	destination = stoll(currentNum);

	currentNum = line.substr(0, line.find(' '));
	line = line.substr(line.find(' ') + 1);

	source = stoll(currentNum);

	range = stoll(line);
}

const Mapping& Mapping::operator=(const Mapping& rhs) {
	if (this != &rhs) 
	{
		destination = rhs.destination;
		source = rhs.source;
		range = rhs.range;
	}

	return *this;
}

// Does math to check if the given number is within the bounds
/*
* If given num is less then the sorce then it's impossible to be in the range.
* Also, if the num is more then the source + the range then it's also impossible.
*/
bool Mapping::withinSourceRange(long long num) {
	return (num >= source) && (source + range > num);
}

// Does math to return the new mapped number given one that is in this mapping
/*
* How far the given number is from the end can be calculated
* Subtracting this difference from the farthest destination tells you what the number will become
*/
// This math gets symplified down to the following equation
// destination - source + the number 
long long Mapping::newDestination(long long num) {
	return destination - source + num;
}
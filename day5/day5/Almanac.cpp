#include "Almanac.h"
#include <iostream>
#include <string>

Almanac::Almanac(string data) {
	// Seed to soil
	{
		data = data.substr(data.find('\n') +1);
		toSoil = makeList(data.substr(0, data.find("\n\n") +1));
		data = data.substr(data.find(':') + 2);
	}
	// Soil to fertilizer
	{
		toFerterlizer = makeList(data.substr(0, data.find("\n\n") +1));
		data = data.substr(data.find(':') + 2);
	}
	// Fertilizer to water
	{
		toWater = makeList(data.substr(0, data.find("\n\n") +1));
		data = data.substr(data.find(':') + 2);
	}
	// Water to light
	{
		toLight = makeList(data.substr(0, data.find("\n\n") +1));
		data = data.substr(data.find(':') + 2);
	}
	// Light to temperature
	{
		toTemp = makeList(data.substr(0, data.find("\n\n") +1));
		data = data.substr(data.find(':') + 2);
	}
	// Temperature to humidity
	{
		toHumidity = makeList(data.substr(0, data.find("\n\n") +1));
		data = data.substr(data.find(':') + 2);
	}
	// Humidity to Locatiomn
	{
		toLocation = makeList(data);
	}
}

list<Mapping> Almanac::makeList(string listData) {

	//listData = listData + '\n';// Adds new line character to end of list

	list<Mapping> currentList;

	string currentLine;

	while (!listData.empty())// Once string is empty the loop ends
	{
		currentLine = listData.substr(0, listData.find_first_of('\n'));
		currentList.push_back(Mapping(currentLine));
		listData = listData.substr(listData.find_first_of('\n') +1);// Creates a shorter version of original string
	}
	/*
	currentList.push_back(Mapping(listData));*/

	return currentList;
}

long long Almanac::getLocation(long long num) {
	// To soil
	Mapping currentMap = checkList(toSoil, num);

	if (!currentMap.isDefault())
		num = currentMap.newDestination(num);

	// To fertilizer
	currentMap = checkList(toFerterlizer, num);

	if (!currentMap.isDefault())
		num = currentMap.newDestination(num);
	
	// To water
	currentMap = checkList(toWater, num);

	if (!currentMap.isDefault())
		num = currentMap.newDestination(num);

	// To light
	currentMap = checkList(toLight, num);

	if (!currentMap.isDefault())
		num = currentMap.newDestination(num);
	
	// To temperature
	currentMap = checkList(toTemp, num);

	if (!currentMap.isDefault())
		num = currentMap.newDestination(num);

	// To humidity
	currentMap = checkList(toHumidity, num);

	if (!currentMap.isDefault())
		num = currentMap.newDestination(num);

	// To location
	currentMap = checkList(toLocation, num);

	if (!currentMap.isDefault())
		num = currentMap.newDestination(num);

	return num;
}

Mapping Almanac::checkList(list<Mapping> currentList, int num) {
	
	list<Mapping>::iterator itr = currentList.begin();

	for (itr; itr != currentList.end(); ++itr)
	{
		if ((*itr).withinSourceRange(num))
			return *itr;
	}

	return *new Mapping;
}
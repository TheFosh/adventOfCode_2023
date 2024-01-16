#include "Almanac.h"
#include <iostream>
#include <string>

Almanac::Almanac(string data) {
	// Seed to soil
	{
		data = data.substr(data.find('\n') +1);
		toSoil = makeList(data.substr(0, data.find(':')));
		data = data.substr(data.find(':') + 2);

		for (Mapping m : toSoil)
		{
			cout << m.getDestination() << endl;
		}
	}
	//// Soil to fertilizer
	//{
	//	toFerterlizer = makeList(data.substr(0, data.find(':')));
	//	data = data.substr(data.find(':') + 2);
	//}
	//// Fertilizer to water
	//{
	//	toWater = makeList(data.substr(0, data.find(':')));
	//	data = data.substr(data.find(':') + 2);
	//}
	//// Water to light
	//{
	//	toLight = makeList(data.substr(0, data.find(':')));
	//	data = data.substr(data.find(':') + 2);
	//}
	//// Light to temperature
	//{
	//	toTemp = makeList(data.substr(0, data.find(':')));
	//	data = data.substr(data.find(':') + 2);
	//}
	//// Temperature to humidity
	//{
	//	toHumidity = makeList(data.substr(0, data.find(':')));
	//	data = data.substr(data.find(':') + 2);
	//}
	//// Humidity to Locatiomn
	//{
	//	toLocation = makeList(data.substr(0, data.find(':')));
	//}
}

list<Mapping> Almanac::makeList(string listData) {
	list<Mapping> currentList;

	string currentLine;

	while (listData.find_first_of('\n') != 0)
	{
		currentLine = listData.substr(0, listData.find_first_of('\n'));
		currentList.push_back(Mapping(currentLine));
		listData = listData.substr(listData.find_first_of('\n') +1);
	}
	/*
	currentList.push_back(Mapping(listData));*/

	return currentList;
}

long long Almanac::getLocation(long long num) {
	toFerterlizer.begin();



	return num;
}
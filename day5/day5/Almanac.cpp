#include "Almanac.h"
#include <iostream>

Almanac::Almanac(string data) {
	// Seed to soil
	{
		data = data.substr(data.find('\n') +1);
		toSoil = makeList(data.substr(0, data.find(':')));
		data = data.substr(data.find(':') + 2);
	}
	// Soil to fertilizer
	{
		toFerterlizer = makeList(data.substr(0, data.find(':')));
		data = data.substr(data.find(':') + 2);
	}
	// Fertilizer to water
	{
		toWater = makeList(data.substr(0, data.find(':')));
		data = data.substr(data.find(':') + 2);
	}
	// Water to light
	{
		toLight = makeList(data.substr(0, data.find(':')));
		data = data.substr(data.find(':') + 2);
	}
	// Light to temperature
	{
		toTemp = makeList(data.substr(0, data.find(':')));
		data = data.substr(data.find(':') + 2);
	}
	// Temperature to humidity
	{
		toHumidity = makeList(data.substr(0, data.find(':')));
		data = data.substr(data.find(':') + 2);
	}
	// Humidity to Locatiomn
	{
		toLocation = makeList(data.substr(0, data.find(':')));
	}
}

list<Mapping> Almanac::makeList(string listData) {
	//cout << listData;

	return *new list<Mapping>;
}

long long Almanac::getLocation(long long num) {
	toFerterlizer.begin();



	return num;
}
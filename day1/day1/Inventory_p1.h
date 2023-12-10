//Jake Swanson 1.1: InvetoryHeader_p1 day1_part1
/*
* Header for Inventory object.
* Used to store and minpulte the given string data
*/
#include <iostream>
#include <string>
#include <fstream>
#include <iterator>

using namespace std;

#pragma once
#ifndef INV_P1_H
#define INV_P1_H

class Inventory {
public:
	Inventory();
	bool getData(string);

	void printData();

private:
	string* data;
	int const CAPACITY = 1000;
};

#endif // !INV_P1_H

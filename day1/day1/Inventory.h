//Jake Swanson 1.1: Invetory header
/*
* Header for Inventory object.
* Used to store and minpulte the given string data
*/
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

#pragma once
#ifndef INV_H
#define INV_H

class Inventory {
public:
	Inventory();//Default constructor
	bool getData(string);//Gets all lines from puzzle input file and stores them in the data array
	int viewTotal() const { return totalAnswer; }//Returns the amount of total answer
	void getTotal();//Runs function that gathers all numbers from file and adds to the total
	void printData(); //Prints data in array

private:
	string* data;
	int totalAnswer;
	int const CAPACITY = 1000;
	int index;

	//For part2. Holds a word of the corresponding index number
	const char* numWords[10] = { "zero", "one", "two","three", "four", "five", "six", "seven", "eight", "nine" };

protected:
	int getFirstNum(string);//Given a string, the first num is returned
	int getLastNum(string);//Given a string and using the index, the last num is returned
	int checkWord(string, int);//Given a string and the index of where it starts, returns the number assosiated with string
};

#endif // !INV_H

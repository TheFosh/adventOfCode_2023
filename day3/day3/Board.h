//Jake Swanson: Board object header
/*
* Object that stores a 2D array of chars based on the input of the data
*/

#pragma once
#ifndef B_H_
#define B_H_

#include <string>
#include <iostream>

#include

using namespace std;

class Board 
{
public:
	Board(string);// Makes the board based on the given string for a text file
	int getTotal();// Gets solution to puzzle

protected:
	char* makeBoard();// Creates 2D array for the object
	bool isNum(int, int);// Checks if the char at the current position is a number
	int createNum(int num, int, int);// Creates a number at the current position
	bool checkIfSymbolAround(int num, int, int);// Checks if a number at the given position has a valid symbol

private:
	char* allData;
};

#endif // !B_H_

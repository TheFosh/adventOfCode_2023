//Jake Swanson:
//Inventory object
/*
* Used at storeing and manipulating game objects.
*/

#ifndef INV_H
#define INV_H

#include "Game.h"
#include <list>
#include <string>

class Inventory {
public:
	// Given a string of a text file, 
	// the list of game objects is created using the data file
	Inventory(string);// Constructor
//	~Inventory();// Deconstructor
	int solvePuzzle(int[]);// Puzzle solving method

	///////FOR TESTING////////
	void printInventory();

protected:
	////USED FOR MAKING GAME OBJECT////

	Game makeGame(string);// Given a string for a game, a game object will be generated
//	string spliceComma(string);// Removes comma at the end of a given string.


private:
	list<Game> data;
};

#endif
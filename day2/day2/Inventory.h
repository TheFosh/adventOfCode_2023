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
	Inventory(string);
	int solvePuzzle(int* );// Puzzle solving method

	///FOR PART 2///
	// Creates list containing game objects with min sets
	list<Game> getMinSet();

	///////FOR TESTING////////
	void printInventory();

protected:
	////USED FOR MAKING GAME OBJECT////
	Game makeGame(string);// Given a string for a game, a game object will be generated
	int countSemiColan(string);// Given a strign for a game, the number of semi colans in it is counted

private:
	list<Game> data;
};

#endif
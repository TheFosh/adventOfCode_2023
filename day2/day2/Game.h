//Jake Swanson:
//Game object header file
/*
* Used to store each of the sets of the colors shown in each game.
*/

#ifndef G_H
#define G_H

#include <fstream>
#include <iostream>

using namespace std;

class Game {
public:
	Game(); // Default constuctor
	Game(int* r, int, int* b, int, int* g, int); // Constructor given int pointers of arrays
	~Game(); // Deconstructor
	Game(const Game&); // Copy Constructor
	const Game operator=(const Game&); // Assignment overloader

	//////FOR TESTING//////
	void printArrays(); // Returns string contents of arrays
	friend ostream& operator<<(ostream&, const Game&); // Allows for printing game objects


private:
	int* red; // Points to an array for the numbers associated with red
	int redSize; // Stores size of the red array
	int* blue; // Points to an array for the numbers associated with blue
	int blueSize; // Stores size of the blue array
	int* green; // Points to an array for the numbers associated with green
	int greenSize; // Stores size of the green array
};

#endif // !G_H

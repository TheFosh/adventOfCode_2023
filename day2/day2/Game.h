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
	Game(int, int* r, int* b, int* g); // Constructor given int pointers of arrays
	~Game(); // Deconstructor
	Game(const Game&); // Copy Constructor
	const Game operator=(const Game&); // Assignment overloader
	int getSize() { return arraySize; } // Returns size of array

	int* getReds() { return red; }
	int* getBlues() { return blue; }
	int* getGreens() { return green; }

	//////FOR TESTING//////
	void printArrays(); // Returns string contents of arrays
	friend ostream& operator<<(ostream&, const Game&); // Allows for printing game objects


private:
	int arraySize;// Size of all arrays (number of pulls in a game)

	int* red; // Points to an array for the numbers associated with red
	int* blue; // Points to an array for the numbers associated with blue
	int* green; // Points to an array for the numbers associated with green
};

#endif // !G_H

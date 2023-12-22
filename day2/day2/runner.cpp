//Jake Swanson: Advent of Code 2023 - Day 2
// Main runner file
/*
* PART 1
* ------
* A bag is said to hold a different amount of different colored cubes.
* Given an puzzle input("input.txt"), in each "game" a number of each color will be taken out.
* Knowing that each number reavled will be put back in the bag,
* Which games have the possiblilty of being
* {12 red, 13 blue, 14 green}
* Add up the index of all the possible games.
* ------------------------------------------------------------------------------------------------
*/

#include "Inventory.h"

//Prints contents of list object
void printList(list<Game>);

int main() {

	// Creats inventory object with all game objects from given input file.
	Inventory inv("input.txt");

	// HARD CODDED
	// Solution set for part 1
	// Number correspnding to color wanted
	// {red, blue, green}
	int solution[] = {12,14,13};

	// Given the solution set,
	// the inventory method, solveProblem, prints out solution to puzzle
	// cout << inv.solvePuzzle(solution); // My answer- 2512

	///PART 2///
	// Given all games in the input games,
	// make the minimum possible set of a game.
	// Sum the power of the numbers found in that set (answer)
	list<Game> myList = inv.getMinSet();

	//printList(myList);
}

///FOR TESTING///
void printList(list<Game> _list) {

	list<Game>::iterator itr = _list.begin();

	for (itr; itr != _list.end(); ++itr)
	{
		cout << *itr << endl;
	}
}
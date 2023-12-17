//Jake Swanson:
//Inventory object
/*
* Used at storeing and manipulating game objects.
*/

#ifndef INV_H
#define INV_H

#include "Game.h"

class Inventory {
public:
	Inventory();

private:
	int CAPACITY = 500;
	Game* data;
};

#endif
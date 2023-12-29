//Jake Swanson: Location class header
/*
* Stores coordinates for a value of type char
*/

#pragma once
#ifndef L_H_
#define L_H_

class Location
{
public:
	Location();
	Location(char);
	Location& operator=(const Location&);
	int getXPos() { return x_position; }
	int getYPos() { return y_position; }
	char getValue() { return value; }

private:
	char value;
	int x_position;
	int y_position;
};

#endif // !L_H_

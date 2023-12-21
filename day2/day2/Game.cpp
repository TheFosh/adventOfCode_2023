// Jake Swanson:
// Game object implementation

#include "Game.h"

Game::Game() {
	red = nullptr;
	blue = nullptr;
	green = nullptr;
}

Game::Game(int _size, int* _red, int* _blue, int* _green) {

	arraySize = _size;

	red = new int[_size];
	for (int i = 0; i < _size; ++i) {
		red[i] = _red[i];
	}

	blue = new int[_size];
	for (int i = 0; i < _size; ++i) {
		blue[i] = _blue[i];
	}

	green = new int[_size];
	for (int i = 0; i < _size; ++i) {
		green[i] = _green[i];
	}
}

Game::~Game() {
	delete[] red;
	red = nullptr;

	delete[] blue;
	blue = nullptr;

	delete[] green;
	green = nullptr;
}

Game::Game(const Game& obj) {

	arraySize = obj.arraySize;

	red = new int[obj.arraySize];
	for (int i = 0; i < obj.arraySize; ++i) {
		red[i] = obj.red[i];
	}

	blue = new int[obj.arraySize];
	for (int i = 0; i < obj.arraySize; ++i) {
		blue[i] = obj.blue[i];
	}

	green = new int[obj.arraySize];
	for (int i = 0; i < obj.arraySize; ++i) {
		green[i] = obj.green[i];
	}
}

const Game Game::operator=(const Game& rhs) {
	if (this != &rhs) 
	{
		delete[] red;
		delete[] blue;
		delete[] green;

		arraySize = rhs.arraySize;

		red = new int[rhs.arraySize];
		for (int i = 0; i < rhs.arraySize; ++i) {
			red[i] = rhs.red[i];
		}

		blue = new int[rhs.arraySize];
		for (int i = 0; i < rhs.arraySize; ++i) {
			blue[i] = rhs.blue[i];
		}

		green = new int[rhs.arraySize];
		for (int i = 0; i < rhs.arraySize; ++i) {
			green[i] = rhs.green[i];
		}
	}

	return *this;
}

void Game::printArrays() {
	cout << "-----Red-----" << endl;

	for (int i = 0; i < arraySize; ++i) {
		cout << red[i] << endl;
	}

	cout << "-----Blue-----" << endl;

	for (int i = 0; i < arraySize; ++i) {
		cout << blue[i] << endl;
	}

	cout << "-----Green-----" << endl;

	for (int i = 0; i < arraySize; ++i) {
		cout << green[i] << endl;
	}
}

ostream& operator<<(ostream& out, const Game& obj) {
	cout << "-----Red-----\n";

	for (int i = 0; i < obj.arraySize; ++i) {
		cout << obj.red[i] << endl;
	}

	cout << "-----Blue-----" << endl;

	for (int i = 0; i < obj.arraySize; ++i) {
		cout << obj.blue[i] << endl;
	}

	cout << "-----Green-----" << endl;

	for (int i = 0; i < obj.arraySize; ++i) {
		cout << obj.green[i] << endl;
	}

	return out;
}
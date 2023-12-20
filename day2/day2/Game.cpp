// Jake Swanson:
// Game object implementation

#include "Game.h"

Game::Game() {
	red = nullptr;
	blue = nullptr;
	green = nullptr;
}

Game::Game(int* _red, int* _blue, int* _green) {

	red = new int[COLOR_CAPACITY];

	for (int i = 0; i < COLOR_CAPACITY; ++i) {
		red[i] = _red[i];
	}

	blue = new int[COLOR_CAPACITY];

	for (int i = 0; i < COLOR_CAPACITY; ++i) {
		blue[i] = _blue[i];
	}

	green = new int[COLOR_CAPACITY];

	for (int i = 0; i < COLOR_CAPACITY; ++i) {
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

	red = new int[obj.COLOR_CAPACITY];

	for (int i = 0; i < obj.COLOR_CAPACITY; ++i) {
		red[i] = obj.red[i];
	}

	blue = new int[obj.COLOR_CAPACITY];

	for (int i = 0; i < obj.COLOR_CAPACITY; ++i) {
		blue[i] = obj.blue[i];
	}

	green = new int[obj.COLOR_CAPACITY];

	for (int i = 0; i < obj.COLOR_CAPACITY; ++i) {
		green[i] = obj.green[i];
	}
}

const Game Game::operator=(const Game& rhs) {
	if (this != &rhs) 
	{
		delete[] red;
		delete[] blue;
		delete[] green;

		red = new int[rhs.COLOR_CAPACITY];

		for (int i = 0; i < rhs.COLOR_CAPACITY; ++i) {
			red[i] = rhs.red[i];
		}

		blue = new int[rhs.COLOR_CAPACITY];

		for (int i = 0; i < rhs.COLOR_CAPACITY; ++i) {
			blue[i] = rhs.blue[i];
		}

		green = new int[rhs.COLOR_CAPACITY];

		for (int i = 0; i < rhs.COLOR_CAPACITY; ++i) {
			green[i] = rhs.green[i];
		}
	}

	return *this;
}

void Game::printArrays() {
	cout << "-----Red-----" << endl;

	for (int i = 0; i < COLOR_CAPACITY; ++i) {
		cout << red[i] << endl;
	}

	cout << "-----Blue-----" << endl;

	for (int i = 0; i < COLOR_CAPACITY; ++i) {
		cout << blue[i] << endl;
	}

	cout << "-----Green-----" << endl;

	for (int i = 0; i < COLOR_CAPACITY; ++i) {
		cout << green[i] << endl;
	}
}

ostream& operator<<(ostream& out, const Game& obj) {
	cout << "-----Red-----\n";

	for (int i = 0; i < obj.COLOR_CAPACITY; ++i) {
		cout << obj.red[i] << endl;
	}

	cout << "-----Blue-----" << endl;

	for (int i = 0; i < obj.COLOR_CAPACITY; ++i) {
		cout << obj.blue[i] << endl;
	}

	cout << "-----Green-----" << endl;

	for (int i = 0; i < obj.COLOR_CAPACITY; ++i) {
		cout << obj.green[i] << endl;
	}

	return out;
}
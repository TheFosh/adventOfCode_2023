// Jake Swanson:
// Game object implementation

#include "Game.h"

Game::Game() {
	red = nullptr;
	redSize = 0;
	blue = nullptr;
	blueSize = 0;
	green = nullptr;
	greenSize = 0;
}

Game::Game(int* _red, int _rS, int* _blue, int _bS, int* _green, int _gS) {

	red = new int[_rS];
	redSize = _rS;

	for (int i = 0; i < _rS; ++i) {
		red[i] = _red[i];
	}

	blue = new int[_bS];
	blueSize = _bS;

	for (int i = 0; i < _bS; ++i) {
		blue[i] = _blue[i];
	}

	green = new int[_gS];
	greenSize = _gS;

	for (int i = 0; i < _gS; ++i) {
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

	red = new int[obj.redSize];
	redSize = obj.redSize;

	for (int i = 0; i < obj.redSize; ++i) {
		red[i] = obj.red[i];
	}

	blue = new int[obj.blueSize];
	blueSize = obj.blueSize;

	for (int i = 0; i < obj.blueSize; ++i) {
		blue[i] = obj.blue[i];
	}

	green = new int[obj.greenSize];
	greenSize = obj.greenSize;

	for (int i = 0; i < obj.greenSize; ++i) {
		green[i] = obj.green[i];
	}
}

const Game Game::operator=(const Game& rhs) {
	if (this != &rhs) 
	{
		delete[] red;
		delete[] blue;
		delete[] green;

		red = new int[rhs.redSize];
		redSize = rhs.redSize;

		for (int i = 0; i < rhs.redSize; ++i) {
			red[i] = rhs.red[i];
		}

		blue = new int[rhs.blueSize];
		blueSize = rhs.blueSize;

		for (int i = 0; i < rhs.blueSize; ++i) {
			blue[i] = rhs.blue[i];
		}

		green = new int[rhs.greenSize];
		greenSize = rhs.greenSize;

		for (int i = 0; i < rhs.greenSize; ++i) {
			green[i] = rhs.green[i];
		}
	}

	return *this;
}

void Game::printArrays() {
	cout << "-----Red-----" << endl;

	for (int i = 0; i < redSize; ++i) {
		cout << red[i] << endl;
	}

	cout << "-----Blue-----" << endl;

	for (int i = 0; i < blueSize; ++i) {
		cout << blue[i] << endl;
	}

	cout << "-----Green-----" << endl;

	for (int i = 0; i < greenSize; ++i) {
		cout << green[i] << endl;
	}
}

ostream& operator<<(ostream& out, const Game& obj) {
	cout << "-----Red-----\n";

	for (int i = 0; i < obj.redSize; ++i) {
		cout << obj.red[i] << endl;
	}

	cout << "-----Blue-----" << endl;

	for (int i = 0; i < obj.blueSize; ++i) {
		cout << obj.blue[i] << endl;
	}

	cout << "-----Green-----" << endl;

	for (int i = 0; i < obj.greenSize; ++i) {
		cout << obj.green[i] << endl;
	}

	return out;
}
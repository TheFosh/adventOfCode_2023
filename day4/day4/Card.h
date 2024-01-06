using namespace std;

#ifndef C_H
#define C_H

class Card {
public:
	Card(string);// Given the line of text, a card object is constructor

	// Getters for the arrays
	int* getNums() { return nums; }
	int* getWinners() { return winners; }

protected:
	void sortWinners();// Sorts the winners array

private:
	int* nums;// Pointer to an array of your numbers
	int* winners;// Pointer to an array of the winning numbers
};

#endif // !C_H


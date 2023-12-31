#include "Card.h"

#include <sstream>
#include <iostream>

Card::Card(string line) {
	line = line.substr(line.find(':') + 1);

	string winnerLine = line.substr(0, line.find('|'));
	string numLine = line.substr(line.find('|') +1);
	
	string numHolder;
	int currNum;

	stringstream winningNums(winnerLine);
	
	int count = 0;
	while (winningNums >> numHolder)
	{
		currNum = stoi(numHolder);
		winners[count] = currNum;

		++count;
	}

	// Sorts winners nums for use later
	sort(winners, winners + WINNER_CAPACITY);

	stringstream yourNums(numLine);

	count = 0;
	while (yourNums >> numHolder)
	{
		currNum = stoi(numHolder);
		nums[count] = currNum;

		++count;
	}
}

const ostream& operator<<(const ostream& out, const Card& c) {

	cout << "Winning nums" << endl;
	cout << "------------" << endl;
	for (int w : c.winners)
	{
		cout << w << endl;
	}
	
	cout << endl;

	cout << "Your nums" << endl;
	cout << "------------" << endl;

	for (int n : c.nums)
	{
		cout << n << endl;
	}

	return out;
}


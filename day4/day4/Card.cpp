#include "Card.h"

#include <sstream>

Card::Card(string line) {
	line = line.substr(line.find(':'));

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

	stringstream yourNums(numLine);

	count = 0;
	while (yourNums >> numHolder)
	{
		currNum = stoi(numHolder);
		nums[count] = currNum;

		++count;
	}
}
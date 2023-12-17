//Jake Swanson:
//Game object header file
/*
* Used to store each of the sets of the colors shown in each game.
*/

#ifndef G_H
#define G_H

using namespace std;

class Game {
public:
	Game();
	~Game();
	Game(const Game&);
	const Game operator=(const Game&);
};

#endif // !G_H

// game.hpp
#ifndef GAME_H 
#define GAME_H 

#include <vector>
#include "player.hpp"
#include "universe.hpp"

class Game{
	Game(){};
	Game& operator=(Game const&){};
	static Game* mInstance;

	public:
	static Game* Instance();
	Player *mainPlayer;
	int deltaX = 0;
	int deltaY = 0;
	int wheelX = 0;
	int wheelY = 0;


	void update(unsigned int);
	void mouse(int x, int y){deltaX += x; deltaY += y;};
	void wheel(int x, int y){wheelX += x; wheelY += y;};
};

#endif

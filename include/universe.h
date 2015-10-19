// universe.h
#ifndef UNIVERSE_H
#define UNIVERSE_H

#include <vector>
#include "player.h"

class Universe {
	Universe(){};
	Universe& operator=(Universe const&){};
	static Universe* mInstance;
public:
	static Universe* Instance();
	std::vector<Player*> playerVector = {};
};

#endif

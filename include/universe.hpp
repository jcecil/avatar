// universe.h
#ifndef UNIVERSE_H
#define UNIVERSE_H

#include <vector>
#include "player.hpp"
#include "entity.hpp"
#include "camera.hpp"

class Universe {
	Universe(){};
	Universe& operator=(Universe const&){};
	static Universe* mInstance;

	public:
	static Universe* Instance();

	Camera* currentCamera;
	std::vector<Player*> playerVector = {};
	std::vector<Entity*> entityVector = {};

	void addPlayer(Player* player){
		currentCamera = player->camera;
		playerVector.push_back(player);};
	void draw(GLuint programID);
	void update();
};

#endif

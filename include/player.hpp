// player.h
#ifndef PLAYER_H
#define PLAYER_H

#include <GL/glew.h>
#include <GL/glu.h>
#include <glm/glm.hpp>
#include "camera.hpp"
#include "entity.hpp"
#include "entityFactory.hpp"

class Player {

	public:
		Camera* camera;
		Entity* entity;
		Player();
		Player(int);
		void draw(Camera*, GLuint);
		void update(int, int, int, int, unsigned int);
};

#endif

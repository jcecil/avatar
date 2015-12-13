// player.h
#ifndef PLAYER_H
#define PLAYER_H

#include <GL/glew.h>
#include <GL/glu.h>
#include <glm/glm.hpp>
#include "camera.h"
#include "entity.h"
#include "entityFactory.h"

class Player {
	Entity* entity;
	Camera* camera;

	public:
	Player();
	void draw(GLuint);
};

#endif

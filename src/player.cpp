#include <GL/glew.h>
#include <GL/glu.h>
#import <stdio.h>
#include "player.hpp"

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

Player::Player() {
	EntityFactory* factory = new EntityFactory();
	camera = new Camera();
	entity = factory->cubeEntity();
}

Player::Player(int derps) {
	EntityFactory* factory = new EntityFactory();
	camera = new Camera();
	entity = factory->triangleEntity();
}

void Player::draw(Camera* currentCamera, GLuint programID) {
	entity->draw(currentCamera, programID);
}

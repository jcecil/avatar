#include <GL/glew.h>
#include <GL/glu.h>
#include "player.h"

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

Player::Player() {
	EntityFactory* factory = new EntityFactory();
	camera = new Camera();
	entity = factory->triangleEntity();
}

void Player::draw(GLuint programID) {
	entity->draw(camera->Projection, camera->View, programID);
}

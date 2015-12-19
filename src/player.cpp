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
	entity = factory->cubeEntityUV();
}

Player::Player(int derps) {
	EntityFactory* factory = new EntityFactory();
	camera = new Camera();
	entity = factory->triangleEntity();
	entity->model = glm::translate(glm::mat4(1.f), glm::vec3(3.f, 0.f, 0.f));

}

void Player::draw(Camera* currentCamera, GLuint programID) {
	entity->draw(currentCamera->PV(), programID);
}

void Player::update(int deltax, int deltay, int wheelx, int wheely, unsigned int deltaTime){
	entity->update(deltaTime);
	camera->update(deltax, deltay, wheelx, wheely,deltaTime, entity); 
}

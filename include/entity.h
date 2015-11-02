// entity.h
#ifndef ENTITY_H
#define ENTITY_H

#ifndef GLM_FORCE_RADIANS
#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Entity {
public:
	
	glm::vec3 position;
	glm::vec3 direction;
	glm::vec3 up;
	glm::mat4 model;
};

#endif // GLM_FORCE_RADIANS
#endif // entity.h

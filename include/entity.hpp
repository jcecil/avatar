// entity.h
#ifndef ENTITY_H
#define ENTITY_H
#include "camera.hpp"

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <GL/glu.h>


class Entity {
	GLuint VertexArrayID;
	GLuint vertexbuffer;
	GLuint colorbuffer;

	GLfloat* vertexData;
	GLfloat* colorData;

	public:
	glm::vec3 position;
	glm::vec3 direction;
	glm::vec3 up;
	glm::mat4 model = glm::mat4(1.0f);
	int vertexDataLength;

	void draw(Camera* camera, GLuint programID);
	void update(unsigned int);
	Entity(GLfloat*, GLfloat*, int);
};

#endif // entity.h

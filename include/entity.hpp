// entity.h
#ifndef ENTITY_H
#define ENTITY_H

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <GL/glu.h>
#include "media.hpp"

class Entity {
	GLuint VertexArrayID;
	GLuint vertexbuffer;
	GLuint colorbuffer;
	GLuint uvbuffer;

	GLuint Texture;
	GLuint TextureID;

	GLfloat* vertexData;
	GLfloat* colorData;
	GLfloat* uvData;

	public:
	glm::vec3 position = glm::vec3(0.f, 0.f, 0.f);
	glm::vec3 direction;
	glm::vec3 up;
	glm::mat4 model = glm::mat4(1.0f);
	int vertexDataLength;

	void draw(glm::mat4 PV, GLuint programID);
	void update(unsigned int);
	Entity(GLfloat*, GLfloat*, GLfloat*, int);
};

#endif // entity.h

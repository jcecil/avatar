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
	// This will identify our vertex buffer
	GLuint vertexbuffer;

	GLfloat* g_vertex_buffer_data;

	public:
	glm::vec3 position;
	glm::vec3 direction;
	glm::vec3 up;
	glm::mat4 model;
	int vertexDataLengh;

	void draw(Camera* camera, GLuint programID);
	Entity(GLfloat *vertexData, int);
};

#endif // entity.h

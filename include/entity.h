// entity.h
#ifndef ENTITY_H
#define ENTITY_H

#ifndef GLM_FORCE_RADIANS
#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <GL/glu.h>

class Entity {
	GLuint VertexArrayID;
	// This will identify our vertex buffer
	GLuint vertexbuffer;

	// An array of 3 vectors which represents 3 vertices
	GLfloat *g_vertex_buffer_data;

	public:
	glm::vec3 position;
	glm::vec3 direction;
	glm::vec3 up;
	glm::mat4 model;

	glm::mat4 Model;
	void draw(glm::mat4 view, glm::mat4 proj, GLuint programID);
	Entity(GLfloat *vertexData);
};

#endif // GLM_FORCE_RADIANS
#endif // entity.h

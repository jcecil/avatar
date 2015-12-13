#include <GL/glew.h>
#include <GL/glu.h>
#include <stdio.h>
#include <stdio.h>
#include "entity.hpp"

Entity::Entity(GLfloat *vertexDataIn, GLfloat *colorDataIn, int dataLength){
	vertexData = vertexDataIn;
	colorData = colorDataIn;
	vertexDataLength = dataLength;

	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);

	glGenBuffers(1, &vertexbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, dataLength, vertexData, GL_STATIC_DRAW);

	glGenBuffers(1, &colorbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
	glBufferData(GL_ARRAY_BUFFER, dataLength, colorData, GL_STATIC_DRAW);
}

void Entity::draw(Camera *camera, GLuint programID){

	// Our ModelViewProjection : multiplication of our 3 matrices
	glm::mat4 MVP        = camera->Projection * camera->View * model; // Remember, matrix multiplication is the other way around

	// Get a handle for our "MVP" uniform.
	// Only at initialisation time.
	GLuint MatrixID = glGetUniformLocation(programID, "MVP");

	// Send our transformation to the currently bound shader,
	// in the "MVP" uniform
	// For each model you render, since the MVP will be different (at least the M part)
	glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

	// 1rst attribute buffer : vertices
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glVertexAttribPointer(
			0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
			3,                  // size
			GL_FLOAT,           // type
			GL_FALSE,           // normalized?
			0,                  // stride
			(void*)0            // array buffer offset
			);

	glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
	glVertexAttribPointer(
			1,                                // attribute. No particular reason for 1, but must match the layout in the shader.
			3,                                // size
			GL_FLOAT,                         // type
			GL_FALSE,                         // normalized?
			0,                                // stride
			(void*)0                          // array buffer offset
			);

	glDrawArrays(GL_TRIANGLES, 0, vertexDataLength/3); 

	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(0);
}

void Entity::update(unsigned int deltaTime){
	float speed = 0.0001f;
	for (int i = 0; i < vertexDataLength/4; i++){
		colorData[i] = colorData[i]+(speed*deltaTime);
		if (colorData[i] > 1){
			colorData[i] -= 1;
		}
	}

	glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
	glBufferData(GL_ARRAY_BUFFER, vertexDataLength, colorData, GL_STATIC_DRAW);

}

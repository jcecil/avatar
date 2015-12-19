#include <GL/glew.h>
#include <GL/glu.h>
#include <stdio.h>
#include <stdio.h>
#include "entity.hpp"

Entity::Entity(GLfloat *vertexDataIn, GLfloat *colorDataIn, GLfloat *uvDataIn, int dataLength){
	vertexData = vertexDataIn;
	colorData = colorDataIn;
	uvData = uvDataIn;
	vertexDataLength = dataLength;

	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);

	glGenBuffers(1, &vertexbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, dataLength*3*4, vertexData, GL_STATIC_DRAW);

	if (colorData != NULL){
		glGenBuffers(1, &colorbuffer);
		glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
		glBufferData(GL_ARRAY_BUFFER, dataLength*3*4, colorData, GL_STATIC_DRAW);
	}

	if (uvDataIn != NULL){
		//TODO do this better
		Texture = loadDDS("assets/textures/uvtemplate.DDS");
		glGenBuffers(1, &uvbuffer);
		glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
		glBufferData(GL_ARRAY_BUFFER, dataLength*2*4, uvData, GL_STATIC_DRAW);

	}

}

void Entity::draw(glm::mat4 PV, GLuint programID){

	// Move this to constructor when you get a chance
	// Get a handle for our "myTextureSampler" uniform
	TextureID  = glGetUniformLocation(programID, "myTextureSampler");

	// Our ModelViewProjection : multiplication of our 3 matrices
	glm::mat4 MVP        = PV * model; // Remember, matrix multiplication is the other way around

	// Get a handle for our "MVP" uniform.
	// Only at initialisation time.
	GLuint MatrixID = glGetUniformLocation(programID, "MVP");

	// Send our transformation to the currently bound shader,
	// in the "MVP" uniform
	// For each model you render, since the MVP will be different (at least the M part)
	glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);

	// Bind our texture in Texture Unit 0
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, Texture);
	// Set our "myTextureSampler" sampler to user Texture Unit 0
	glUniform1i(TextureID, 0);

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

	glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
	glVertexAttribPointer(
			1,                                // attribute. No particular reason for 1, but must match the layout in the shader.
			2,                                // size
			GL_FLOAT,                         // type
			GL_FALSE,                         // normalized?
			0,                                // stride
			(void*)0                          // array buffer offset
			);

	/*
	   glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
	   glVertexAttribPointer(
	   1,                                // attribute. No particular reason for 1, but must match the layout in the shader.
	   3,                                // size
	   GL_FLOAT,                         // type
	   GL_FALSE,                         // normalized?
	   0,                                // stride
	   (void*)0                          // array buffer offset
	   );
	   */

	glDrawArrays(GL_TRIANGLES, 0, vertexDataLength); 

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
}

void Entity::update(unsigned int deltaTime){
	/*float speed = 0.0001f;
	  for (int i = 0; i < vertexDataLength/4; i++){
	  colorData[i] = colorData[i]+(speed*deltaTime);
	  if (colorData[i] > 1){
	  colorData[i] -= 1;
	  }
	  }

	  glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
	  glBufferData(GL_ARRAY_BUFFER, vertexDataLength, colorData, GL_STATIC_DRAW);
	  */
	model = glm::translate(glm::mat4(1.0f), position);
}

// camera.h
#ifndef CAMERA_H 
#define CAMERA_H 

#ifndef GLM_FORCE_RADIANS
#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "entity.hpp"

class Camera {

	// position
	glm::vec3 position = glm::vec3( 4, 3, 3 );

	// horizontal angle : toward -Z
	float horizontalAngle = 3.14f;

	// vertical angle : 0, look at the horizon
	float verticalAngle = 0.0f;

	// Initial Field of View
	float FoV = 90.0f;//45.0f;

	glm::vec3 direction;
	glm::vec3 right;
	glm::vec3 up;

	float speed = 3.0f; // 3 units / second
	float mouseSpeed = 0.0005f;
	float zoomSpeed = 0.0005f;

	public:
	// Projection matrix : 45? Field of View, 4:3 ratio, display range : 0.1 unit <-> 100 units
	glm::mat4 Projection = glm::perspective(45.0f, 4.0f / 3.0f, 0.1f, 100.0f);

	// Camera matrix
	glm::mat4 View= glm::lookAt(
			glm::vec3(4,3,3), // Camera is at (4,3,3), in World Space
			glm::vec3(0,0,0), // and looks at the origin
			glm::vec3(0,1,0)  // Head is up (set to 0,-1,0 to look upside-down)
			);

	void update(int, int, int, int, int, Entity*);
	glm::mat4 PV(){
		return Projection * View;
	}

};

#endif // GLM_FORCE_RADIANS
#endif // camera.h

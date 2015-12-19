#include <stdio.h>
#include "camera.hpp"

void Camera::update(int x, int y, int wheelx, int wheely, int deltaTime, Entity* target){
	horizontalAngle += mouseSpeed * deltaTime * float( x );
	verticalAngle   += mouseSpeed * deltaTime * float( y );

	direction = glm::vec3(
			cos(verticalAngle) * sin(horizontalAngle),
			sin(verticalAngle),
			cos(verticalAngle) * cos(horizontalAngle)
			);

	position = target->position - direction;

	printf("%d,%f\n",deltaTime,mouseSpeed);
	//printf("%f,%f\n",horizontalAngle,verticalAngle);
	//printf("%f,%f,%f\n", cos(verticalAngle) * sin(horizontalAngle),	sin(verticalAngle),cos(verticalAngle) * cos(horizontalAngle));

	right = glm::vec3(
			sin(horizontalAngle - 3.14f/2.0f),
			0,
			cos(horizontalAngle - 3.14f/2.0f)
			);

	up = glm::cross( right, direction );

	FoV -= zoomSpeed * deltaTime * wheely;

	Projection = glm::perspective(FoV, 4.0f / 3.0f, 0.1f, 100.0f);

	View = glm::lookAt(
			position,           // Camera is here
			position+direction, // and looks here : at the same position, plus "direction"
			up                  // Head is up (set to 0,-1,0 to look upside-down)
			);


}

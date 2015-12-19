#import "universe.hpp"

Universe* Universe::mInstance = nullptr;

Universe* Universe::Instance()
{
	if (!mInstance)   // Only allow one instance of class to be generated.
		mInstance = new Universe();
	return mInstance;
}

void Universe::draw(GLuint programID){
	glm::mat4 PV = currentCamera->PV();//rojection * currentCamera->View;

	for (std::vector<Entity*>::iterator it = entityVector.begin(); it != entityVector.end(); ++it){                                         
		(*it)->draw(PV, programID); 
	}

	for (std::vector<Player*>::iterator it = playerVector.begin(); it != playerVector.end(); ++it){                                         
		(*it)->draw(currentCamera, programID); 
	}
}

void Universe::update(unsigned int deltaTime){
	for (std::vector<Entity*>::iterator it = entityVector.begin(); it != entityVector.end(); ++it){                                         
		(*it)->update(deltaTime); 
	}

	//	for (std::vector<Player*>::iterator it = playerVector.begin(); it != playerVector.end(); ++it){                                         
	//		(*it)->update(deltaTime); 
	//	}
}

#import "universe.hpp"

Universe* Universe::mInstance = nullptr;

Universe* Universe::Instance()
{
	if (!mInstance)   // Only allow one instance of class to be generated.
		mInstance = new Universe();
	return mInstance;
}

void Universe::draw(GLuint programID){
	for (std::vector<Entity*>::iterator it = entityVector.begin(); it != entityVector.end(); ++it){                                         
		(*it)->draw(currentCamera, programID); 
		//		printf("entities");
	}

	for (std::vector<Player*>::iterator it = playerVector.begin(); it != playerVector.end(); ++it){                                         
		(*it)->draw(currentCamera, programID); 
		//		printf("players");
	}
}

void Universe::update(){

}

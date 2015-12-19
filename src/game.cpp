#import "game.hpp"

Game* Game::mInstance = nullptr;

Game* Game::Instance()
{
	if (!mInstance)   // Only allow one instance of class to be generated.
		mInstance = new Game();
	return mInstance;
}

void Game::update(unsigned int deltaTime){

	bool inGame = true;
	if (inGame){
		mainPlayer->update(deltaX,deltaY,wheelX,wheelY,deltaTime);
		deltaX = 0;
		deltaY = 0;
		wheelX = 0;
		wheelY = 0;
	}
	Universe::Instance()->update(deltaTime);
}


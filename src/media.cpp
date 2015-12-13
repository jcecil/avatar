#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include "media.hpp"

bool loadMedia(SDL_Surface* screen, SDL_Surface* world){
	bool success = true;

	screen = loadSurface("assets/images/preview.png", world->format);
	if (screen == NULL)
	{
		printf( "Unable to load image!!!\n");
		printf( SDL_GetError() );
		success = false;
	}
	return success;
}

SDL_Surface* loadSurface( std::string path , SDL_PixelFormat* format )
{
	//The final optimized image
	SDL_Surface* optimizedSurface = NULL;
	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	else
	{
		//Convert surface to screen format
		optimizedSurface = SDL_ConvertSurface( loadedSurface, format, NULL );
		if( optimizedSurface == NULL )
		{
			printf( "Unable to optimize image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}
		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}
	return optimizedSurface;
}

/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

//Using SDL, SDL_image, standard IO, and strings
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string>
#include "window.h"
#include "input.h"

//Starts up SDL and creates window
bool init();

//Loads media
//bool loadMedia();

//Frees media and shuts down SDL
void close();

//Loads individual image
SDL_Surface* loadSurface( std::string path );

//The window we'll be rendering to
Window* gWindow = NULL;

//The surface contained by the window
//SDL_Surface* gScreenSurface = NULL;

//Current displayed PNG image
SDL_Surface* gPNGSurface = NULL;

bool init()
{
    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
        return false;
    }

    //Create window
    gWindow = new Window();

    //Initialize PNG loading
    int imgFlags = IMG_INIT_PNG;
    if( !( IMG_Init( imgFlags ) & imgFlags ) )
    {
        printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
        return false;
    }

    //Get window surface
    //gScreenSurface = gWindow->getWindowSurface();

    return true;
}

/*
bool loadMedia(std::string filename)
{
    //Loading success flag
    bool success = true;

    //Load PNG surface
    gPNGSurface = loadSurface( filename );
    if( gPNGSurface == NULL )
    {
        printf( "Failed to load PNG image!\n" );
        success = false;
    }

    return success;
}



SDL_Surface* loadSurface( std::string path )
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
        optimizedSurface = SDL_ConvertSurface( loadedSurface, gScreenSurface->format, NULL );
        if( optimizedSurface == NULL )
        {
            printf( "Unable to optimize image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
        }

        //Get rid of old loaded surface
        SDL_FreeSurface( loadedSurface );
    }

    return optimizedSurface;
}
*/

int main( int argc, char* args[] )
{
    //Start up SDL and create window
    if( !init() )
    {
        printf( "Failed to initialize!\n" );
    }
    else
    {
	    /*
        //Load media
        if( !loadMedia( "assets/images/arena.png" ) )
        {
            printf( "Failed to load media!\n" );
        }
        else*/
        {
            //While application is running
            while( !readInput() )
            {
                //Apply the PNG image
                //SDL_BlitSurface( gPNGSurface, NULL, gScreenSurface, NULL );

                //Update the surface
                //gWindow->updateWindowSurface();

			//Render quad
            printf( "bout to render quad!\n" );
			gWindow->render();
            printf( "after render quad!\n" );
			
			            }
        }
    }

    //Free resources and close SDL
    close();

    return 0;
}

void close()
{
    //Free loaded image
    SDL_FreeSurface( gPNGSurface );
    gPNGSurface = NULL;

    //Destroy window
    gWindow->destroyWindow();
    delete gWindow;
    gWindow = NULL;

    //Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
}

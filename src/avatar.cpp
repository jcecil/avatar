/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

//Using SDL, SDL_image, standard IO, and strings
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string>
#include "window.h"
#include "player.h"
#include "input.h"
#include "universe.h"
#include "universe.h"

//Starts up SDL and creates window
bool init();

//Frees media and shuts down SDL
void close();

//The window we'll be rendering to
Window* gWindow = NULL;
Player* gPlayer = NULL;

int main( int argc, char* args[] )
{
    //Start up SDL and create window
    if( !init() )
    {
        printf( "Failed to initialize!\n" );
    }
    else
    {
        //While application is running
        while( !readInput() )
        {
            //Render quad
            gWindow->render();
        }
    }

    //Free resources and close SDL
    close();

    return 0;
}

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
    //gPlayer = new Player();
        printf( "derpsosifso" );
    Universe::Instance()->playerVector.push_back(new Player());

    return true;
}
void close()
{
    //Destroy window
    gWindow->destroyWindow();
    delete gWindow;
    gWindow = NULL;

    //Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
}

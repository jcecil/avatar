// Avatar

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <media.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

bool init();
void close();

bool quit = false;
SDL_Event e;
//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;
SDL_Surface* gHelloWorld = NULL;



int main()
{
    if (!init()) {
        printf("Failed to initialize!!!!!!!!!!!!!");
    } else {
        if (!loadMedia(gHelloWorld, gScreenSurface) )
        {
            printf( " failed to load media\n");
        } else {
            // Apply the image
            SDL_BlitSurface( gHelloWorld, NULL, gScreenSurface, NULL );
            SDL_UpdateWindowSurface( gWindow );
            SDL_Delay(2000);
        }
    }

    while (!quit)
    {
        while( SDL_PollEvent(&e) != 0)
        {
            if (e.type == SDL_QUIT)
            {
                quit = true;
            }
        }
    }

    close();

    std::cout << "Hello World!";
}

bool init () {
    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        return false;
    }

    //Create window
    gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
    if( gWindow == NULL )
    {
        printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
        return false;
    }

    //Initialize PNG loading
    int imgFlags = IMG_INIT_PNG;
    if( !( IMG_Init( imgFlags ) & imgFlags ) )
    {
        printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
        return false;
    }

    //Get window surface
    gScreenSurface = SDL_GetWindowSurface( gWindow );
    return true;
}

void close() {
    //Deallocate surface
    SDL_FreeSurface( gHelloWorld );
    gHelloWorld = NULL;

    //Destroy window
    SDL_DestroyWindow( gWindow);
    gWindow = NULL;

    SDL_Quit();
}

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "window.h"

Window::Window() {
    gWindow = SDL_CreateWindow( title, xpos, ypos, width, height, windowFlags );

    if( gWindow == NULL )
    {
        printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
    }
}

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

void PrintKeyInfo( SDL_KeyboardEvent *key ) {
    if( key->type == SDL_KEYUP )
        printf( "Release:- " );
    else
        printf( "Press:- " );

    printf( "Scancode: 0x%02X", key->keysym.scancode );
    printf( ", Name: %s", SDL_GetKeyName( key->keysym.sym ) );
    if( key->type == SDL_KEYDOWN ) {
    }
    printf( "\n" );
}

bool readInput() {
    static SDL_Event e;
    static bool quit = false;

    //Handle events on queue
    while( SDL_PollEvent( &e ) != 0 )
    {
        switch(e.type) {
        case SDL_QUIT:
            quit = true;
            break;
        case SDL_KEYDOWN:
        case SDL_KEYUP:
            PrintKeyInfo(&e.key);
            if (e.key.keysym.sym == SDLK_ESCAPE) {
                quit = true;
            }
            break;
        }
    }
    return quit;
}



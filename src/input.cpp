#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

/* Print modifier info 
void PrintModifiers( SDLMod mod ) {
    printf( "Modifers: " );

    if( mod == KMOD_NONE ) {
        printf( "None\n" );
        return;
    }

    if( mod & KMOD_NUM ) printf( "NUMLOCK " );
    if( mod & KMOD_CAPS ) printf( "CAPSLOCK " );
    if( mod & KMOD_LCTRL ) printf( "LCTRL " );
    if( mod & KMOD_RCTRL ) printf( "RCTRL " );
    if( mod & KMOD_RSHIFT ) printf( "RSHIFT " );
    if( mod & KMOD_LSHIFT ) printf( "LSHIFT " );
    if( mod & KMOD_RALT ) printf( "RALT " );
    if( mod & KMOD_LALT ) printf( "LALT " );
    if( mod & KMOD_CTRL ) printf( "CTRL " );
    if( mod & KMOD_SHIFT ) printf( "SHIFT " );
    if( mod & KMOD_ALT ) printf( "ALT " );
    printf( "\n" );
}
*/


/* Print all information about a key event */
void PrintKeyInfo( SDL_KeyboardEvent *key ) {
    /* Is it a release or a press? */
    if( key->type == SDL_KEYUP )
        printf( "Release:- " );
    else
        printf( "Press:- " );

    /* Print the hardware scancode first */
    printf( "Scancode: 0x%02X", key->keysym.scancode );
    /* Print the name of the key */
    printf( ", Name: %s", SDL_GetKeyName( key->keysym.sym ) );
    /* We want to print the unicode info, but we need to make */
    /* sure its a press event first (remember, release events */
    /* don't have unicode info                                */
    if( key->type == SDL_KEYDOWN ) {
        /* If the Unicode value is less than 0x80 then the    */
        /* unicode value can be used to get a printable       */
        /* representation of the key, using (char)unicode.    */
        printf(", Unicode: " );
        //if( key->keysym.unicode < 0x80 && key->keysym.unicode > 0 ) {
        //    printf( "%c (0x%04X)", (char)key->keysym.unicode,
        //            key->keysym.unicode );
        //}
        //else {
        //    printf( "? (0x%04X)", key->keysym.unicode );
        //}
    }
    printf( "\n" );
    /* Print modifier info */
 //   PrintModifiers( key->keysym.mod );
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
            break;
        }
    }
    return quit;
}



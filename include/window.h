// window.h
#ifndef WINDOW_H
#define WINDOW_H

#include <GL/glew.h>
#include <SDL2/SDL_opengl.h>
#include <GL/glu.h>
#include "player.h"

class Window {
    const char* title = "Mah Vidja game";
    SDL_Window* gWindow = NULL;

    int xpos = SDL_WINDOWPOS_UNDEFINED;
    int ypos = SDL_WINDOWPOS_UNDEFINED;
    int width = 640;
    int height = 480;
    unsigned int windowFlags = SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN;

    SDL_GLContext gContext;
    GLuint gProgramID = 0;
    GLint gVertexPos2DLocation = -1;
    GLuint gVBO = 0;
    GLuint gIBO = 0;
    
    bool initGL();
    void printShaderLog( GLuint );
    void printProgramLog( GLuint );
    
public:
    Window();

    SDL_Surface* getWindowSurface()    { return SDL_GetWindowSurface(gWindow); };
    void         destroyWindow()       ;
    void         updateWindowSurface() { SDL_UpdateWindowSurface(gWindow);     };
    void         render(Player*);
};

#endif

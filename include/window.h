// window.h
#ifndef WINDOW_H
#define WINDOW_H

class Window {
    int xpos = SDL_WINDOWPOS_UNDEFINED;
    int ypos = SDL_WINDOWPOS_UNDEFINED;
    int width = 640;
    int height = 480;
    unsigned int windowFlags = SDL_WINDOW_SHOWN;
    SDL_Window* gWindow = NULL;
    const char* title = "Mah Vidja game";
public:
    Window();
    SDL_Surface* getWindowSurface()    { return SDL_GetWindowSurface(gWindow); };
    void         destroyWindow()       { SDL_DestroyWindow(gWindow);           };
    void         updateWindowSurface() { SDL_UpdateWindowSurface(gWindow);     };
};

#endif

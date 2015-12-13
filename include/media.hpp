#ifndef MEDIA_HPP
#define MEDIA_HPP

#include <GL/glu.h>

//SDL_Surface* loadSurface(std::string, SDL_PixelFormat* format);

//bool loadMedia(SDL_Surface* screen, SDL_Surface* world);

// Load a .DDS file using GLFW's own loader
GLuint loadDDS(const char * imagepath);

#endif //MEDIA_HPP

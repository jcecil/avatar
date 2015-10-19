// player.h
#ifndef PLAYER_H
#define PLAYER_H

#include <GL/glew.h>
#include <GL/glu.h>

class Player {
    GLuint VertexArrayID;
    // This will identify our vertex buffer
    GLuint vertexbuffer;

    // An array of 3 vectors which represents 3 vertices
    GLfloat g_vertex_buffer_data[9] = {
        -1.0f, -1.0f, 0.0f,
        1.0f, -1.0f, 0.0f,
        0.0f,  1.0f, 0.0f,
    };

public:
    Player();
    void draw(GLuint);
};

#endif

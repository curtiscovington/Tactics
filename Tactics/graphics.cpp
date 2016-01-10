#include "graphics.h"
#include <SDL2/SDL.h>
#include <OpenGL/gl3.h>
#include <stdlib.h>
#include <chrono>

Graphics::Graphics() {
    
    SDL_LogSetAllPriority(SDL_LOG_PRIORITY_VERBOSE);
    
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    
    if (0 != SDL_Init(SDL_INIT_VIDEO)) {
        fprintf(stderr, "\nUnable to initialize SDL: %s\n", SDL_GetError());
    }
    
    int width = 800;
    int height = 600;
    mWindow = SDL_CreateWindow("Title", 0, 0, width, height, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
    
    if (mWindow == 0) {
        SDL_Quit();
    } else {
        mGL = SDL_GL_CreateContext(mWindow);
    }
}

Graphics::~Graphics() {
    SDL_GL_DeleteContext(mGL);
    SDL_DestroyWindow(mWindow);
    SDL_Quit();
}
void Graphics::update( std::chrono::milliseconds dt) {
    glClearColor(rand() % 255/255.0f,rand() % 255/255.0f,rand() % 255/255.0f,1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT |  GL_STENCIL_BUFFER_BIT);
    SDL_GL_SwapWindow(mWindow);
}
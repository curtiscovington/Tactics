#ifndef GRAPHICS_H
#define GRAPHICS_H
#include <chrono>
#include <SDL2/SDL.h>

class Graphics {
public:
    Graphics();
    ~Graphics();
    void update(std::chrono::milliseconds dt);
private:
    SDL_Window* mWindow;
    SDL_GLContext mGL;
};

#endif

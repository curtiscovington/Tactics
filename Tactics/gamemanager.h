#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <SDL2/sdl.h>
#include <chrono>
#include <iostream>

class Graphics;

using Clock = std::chrono::high_resolution_clock;

class GameManager {
public:
    GameManager();
    ~GameManager();
    void loop();
    
private:
    std::chrono::time_point<Clock> mStartTime;
    std::chrono::time_point<Clock> mCurrentTime;
    std::chrono::time_point<Clock> mLastTime;
    std::unique_ptr<Graphics> mGraphics;
};

#endif
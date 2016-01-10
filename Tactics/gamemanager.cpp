#include "gamemanager.h"
#include <chrono>
#include <iostream>
#include "graphics.h"
#include <SDL2/SDL.h>

GameManager::GameManager() {
    mStartTime = Clock::now();
    mLastTime = mStartTime;
    mGraphics = std::unique_ptr<Graphics>(new Graphics());
}

GameManager::~GameManager() {
    
}

void GameManager::loop() {
    mCurrentTime = Clock::now();
    std::chrono::milliseconds dt = std::chrono::duration_cast<std::chrono::milliseconds>(mCurrentTime - mLastTime);
    mLastTime = mCurrentTime;
    std::cout << "e:" << dt.count() << std::endl;
    if (dt > std::chrono::milliseconds(0)) {
        mGraphics->update(dt);
    }
}
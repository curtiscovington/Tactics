//
//  main.cpp
//  Tactics
//
//  Created by Curtis Covington on 1/1/16.
//  Copyright © 2016 Curtis Covington. All rights reserved.
//

#include <iostream>
#include <SDL2/SDL.h>
#include <OpenGL/OpenGL.h>
#include "graphics.h"
#include "gamemanager.h"
#include <ctime>
#include "entity.h"
#include "component.h"

int EventFilter(void* data, SDL_Event* event) {
    switch(event->type) {
        case SDL_KEYDOWN:
            SDL_Log("Key Down %d", event->key.keysym.sym);
            return 0;
        case SDL_KEYUP:
            SDL_Log("Key UP %d", event->key.keysym.sym);
            return 0;
        case SDL_MOUSEMOTION:
            SDL_Log("Mouse Moved. X=%d, Y=%d, RelativeX=%d, RelativeY=%d", event->motion.x, event->motion.y, event->motion.xrel, event->motion.yrel);
            return 0;
        case SDL_MOUSEBUTTONDOWN:
            SDL_Log("Mouse Button Down %d", event->button.button);
            return 0;
        case SDL_MOUSEBUTTONUP:
            SDL_Log("Mouse Button UP %d", event->button.button);
            return 0;
        case SDL_MOUSEWHEEL:
            SDL_Log("Mouse Wheel.");
            return 0;
    }
    return 1;
}


int main(int argc, const char * argv[]) {
    GameManager g;
    
    SDL_AddEventWatch(EventFilter, nullptr);
    SDL_Event event;
    
    //time_t start = std::time(nullptr);
    bool done = false;
    while (!done) {
        SDL_PumpEvents();
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    done = true;
                    break;
            }
        }
        
        //graphics->update(window, 0);
        g.loop();
    }
    
    
    return 0;
}

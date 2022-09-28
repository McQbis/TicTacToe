#ifndef MOUSE_H
#define MOUSE_H

#include <iostream>
#include <SDL2/SDL.h>

class Mouse
{
private:
    SDL_Texture* tex;
    SDL_Rect rect;
    SDL_Rect point;
public:
    Mouse();
    ~Mouse();
    
};

#endif //MOUSE_H
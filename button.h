#ifndef BUTTON_H
#define BUTTON_H

#include <iostream>
#include <SDL2/SDL.h>
#include "object.h"
#include "game.h"

class Button
{
private:
    int x, y;
    Object o;
public:
    friend class Game;
    Button(int x, int y);
    ~Button();
    void placeIt(std::string img, SDL_Renderer *ren);
};

#endif //BUTTON_H


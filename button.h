#ifndef BUTTON_H
#define BUTTON_H

#include <iostream>
#include <SDL2/SDL.h>
#include "object.h"
#include "game.h"
#include "menu.h"

class Button
{
private:
    int x, y;
    Object o;
public:
    friend class Game;
    friend class Menu;
    Button(int x, int y);
    ~Button();
    void placeIt(SDL_Renderer *ren);
};

#endif //BUTTON_H


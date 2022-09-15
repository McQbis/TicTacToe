#ifndef PLAYERSTURN_H
#define PLAYERSTURN_H

#include <iostream>
#include <SDL2/SDL.h>
#include "object.h"

class PlayerTurn:public Object
{
private:
    Object o;
    char state;
public:
    PlayerTurn(char='o');
    ~PlayerTurn() {}
    void placeIt(SDL_Renderer* ren);
};

#endif //PLAYERSTURN_H
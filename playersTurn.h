#ifndef PLAYERSTURN_H
#define PLAYERSTURN_H

#include <iostream>
#include <SDL2/SDL.h>
#include "object.h"
#include "game.h"

class PlayerTurn:public Object
{
private:
    Object o;
    char state;
public:
    friend class Game;
    PlayerTurn(char='o');
    ~PlayerTurn() {}
    void placeIt(SDL_Renderer* ren);
    void change();
};

#endif //PLAYERSTURN_H
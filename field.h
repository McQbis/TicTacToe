#ifndef FIELD_H
#define FIELD_H

#include <iostream>
#include <SDL2/SDL.h>
#include "object.h"
#include "game.h"

class Field:public Object
{
private:
    int x, y;
    Object o;
    char state;
public:
    friend class Game;
    Field(char='n', int=0, int=0);
    ~Field() {}
    void placeIt(SDL_Renderer* ren);
    void setCursor(SDL_Rect mouse);
    void change(char turn, SDL_Renderer* ren);
};

#endif //FIELD_H
#ifndef FIELD_H
#define FIELD_H

#include <iostream>
#include <SDL2/SDL.h>
#include "object.h"

class Field:public Object
{
private:
    int x, y;
    char state;
    Object o;
public:
    Field(char='n', int=0, int=0);
    ~Field() {}
    void placeIt(SDL_Renderer* ren);
};

#endif //FIELD_H
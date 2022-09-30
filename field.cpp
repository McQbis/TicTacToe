#include <iostream>
#include <SDL2/SDL.h>
#include "field.h"

Field::Field(char stat, int x, int y)
{   
    state = stat;
    o.setDest(50+150*x, 50+150*y, 150, 150);
    o.setSrc(0, 0, 150, 150);
}

void Field::placeIt(SDL_Renderer* ren)
{
    if(state == 110){
        o.setImg("img/nic.bmp", ren);
    }else if(state == 111){
        o.setImg("img/o.bmp", ren);
    }else{
        o.setImg("img/x.bmp", ren);
    }
    o.draw(ren);
}

void Field::change(char turn)
{
    switch (turn)
    {
    case 'x':
        state = 'x';
        break;
    
    default:
        state = 'o';
        break;
    }
}




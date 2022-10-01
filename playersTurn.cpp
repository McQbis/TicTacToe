#include <iostream>
#include <SDL2/SDL.h>
#include "playersTurn.h"

PlayerTurn::PlayerTurn(char stat)
{
    state = stat;
    o.setDest(650, 150, 150, 150);
    o.setSrc(0, 0, 150, 150);
}

void PlayerTurn::placeIt(SDL_Renderer* ren)
{
    o.draw(ren);
}

void PlayerTurn::change(SDL_Renderer* ren)
{
    switch (state)
    {
    case 'o':
        state = 'x';
        break;
    
    default:
        state = 'o';
        break;
    }
    if(state == 111){
        o.setImg("img/o.bmp", ren);
    }else{
        o.setImg("img/x.bmp", ren);
    }
}
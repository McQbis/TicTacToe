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

// void Field::setCursor(SDL_Rect mouse)
// {
//     // if (state == 110 & mx > 50+150*x & mx < 200+150*x & my > 50+150*y & my < 200+150*y) 
//     // {
//     //     SDL_SetCursor(SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_HAND));
//     // } else {
//     //     SDL_SetCursor(SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_ARROW));
//     // }

//     if (SDL_HasIntersection(&o.dest, &mouse))
//     {
//         SDL_SetCursor(SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_HAND));
//     } else {
//         SDL_SetCursor(SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_ARROW));
//     }
// }

void Field::change()
{
    state = 'o';
}




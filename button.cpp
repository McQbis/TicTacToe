#include <iostream>
#include <SDL2/SDL.h>
#include "button.h"

Button::Button(int x, int y)
{
    o.setDest(x, y, 350, 100);
    o.setSrc(0, 0, 350, 100);
}

void Button::placeIt(SDL_Renderer *ren)
{
    o.draw(ren);
}

Button::~Button()
{

}
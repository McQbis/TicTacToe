#include <iostream>
#include <SDL2/SDL.h>
#include "button.h"

Button::Button(int x, int y)
{
    o.setDest(x, y, 350, 100);
    o.setSrc(0, 0, 350, 100);
}

void Button::placeIt(std::string img, SDL_Renderer *ren)
{
    o.setImg(img.c_str(), ren);
    o.draw(ren);
}

Button::~Button()
{

}
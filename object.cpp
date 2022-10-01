#include <iostream>
#include <SDL2/SDL.h>
#include "object.h"

using namespace std;

void Object::setDest(int x, int y, int w, int h) {
    dest.x = x;
    dest.y = y;
    dest.w = w;
    dest.h = h;
}

void Object::setSrc(int x, int y, int w, int h) {
    src.x = x;
    src.y = y;
    src.w = w;
    src.h = h;
}

void Object::setImg(string filename, SDL_Renderer* ren) {
    surf = SDL_LoadBMP(filename.c_str());
    surf = SDL_ConvertSurface(surf, surf -> format, 0);
    tex = SDL_CreateTextureFromSurface(ren, surf);
}

void Object::draw(SDL_Renderer* ren)
{
    SDL_RenderCopyEx(ren, tex, &src, &dest, 0 , NULL, SDL_FLIP_NONE);
}

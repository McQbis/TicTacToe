#include <iostream>
#include <SDL2/SDL.h>
#include "object.h"
#include "game.h"

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
    SDL_Surface* surf = SDL_LoadBMP(filename.c_str());
    tex = SDL_CreateTextureFromSurface(ren, surf);
}

void Object::draw(SDL_Renderer* ren)
{
    SDL_Rect dest = getDest();
    SDL_Rect src = getSrc();
    SDL_RenderCopyEx(ren, getTex(), &src, &dest, 0 , NULL, SDL_FLIP_NONE);
}

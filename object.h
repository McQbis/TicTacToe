#ifndef OBJECT_H
#define OBJECT_H

#include <iostream>
#include <SDL2/SDL.h>

using namespace std;

class Object {
private:
    SDL_Rect src;
    SDL_Texture* tex;
    SDL_Surface* surf;
public:
    SDL_Rect dest;
    Object() {}
    ~Object() {}
    void setDest(int x, int y, int w, int h);
    void setSrc(int x, int y, int w, int h);
    void setImg(string filename, SDL_Renderer* ren);
    void draw(SDL_Renderer* ren);
};

#endif //OBJECT_H
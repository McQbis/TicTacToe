#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <SDL2/SDL.h>
#include "object.h"

using namespace std;

class Game
{
private:
    SDL_Renderer* ren;
    SDL_Window* win;
    bool running, fullscreen;
    int count;
    int frameCount, timerFPS, lastFrame;
    Object field;
public:
    friend void Object::draw(SDL_Renderer* ren);
    Game();
    ~Game();
    void loop();
    void update();
    void render();
    void input();
};

#endif //GAME_H


#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <SDL2/SDL.h>
#include "object.h"
#include "field.h"
#include "playersTurn.h"
#include <SDL2/SDL_ttf.h>
#include "button.h"
#include "menu.h"

using namespace std;

class Game
{
private:
    SDL_Renderer* ren;
    SDL_Window* win;
    bool running, fullscreen;
    int count;
    int frameCount, timerFPS, lastFrame;
    TTF_Font* font;
    SDL_Rect rect;
    SDL_Rect mouse;
    SDL_Event e;
    SDL_Surface* fontSurf;
    SDL_Texture* fontTex;
    SDL_Color fontColor;
    SDL_Rect fontRect;

public:
    friend void Object::draw(SDL_Renderer* ren);
    Game();
    ~Game();
    void loop();
    void update();
    void render();
    void input();
    void Font(const char* msg, int x, int y, int r, int g, int b, int a);
};

#endif //GAME_H


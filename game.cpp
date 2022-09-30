#include <iostream>
#include <SDL2/SDL.h>
#include "game.h"

using namespace std;

Field f1('n', 0, 0);
Field f2('n', 0, 1);
Field f3('n', 0, 2);
Field f4('n', 1, 0);
Field f5('n', 1, 1);
Field f6('n', 1, 2);
Field f7('n', 2, 0);
Field f8('n', 2, 1);
Field f9('n', 2, 2);
PlayerTurn turn('o');

Game::Game()
{
    SDL_Init(0);
    SDL_CreateWindowAndRenderer(1000, 600, 0, &win, &ren);
    SDL_SetWindowTitle(win, "Kółko i krzyżyk");
    TTF_Init();
    font = TTF_OpenFont("Sans.ttf", 70);
    running = true;
    count = 0;
    loop();
}

Game::~Game()
{
    TTF_Quit();
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();
}

void Game::loop()
{
    lastFrame = SDL_GetTicks();
    static int lastTime;
    if (lastFrame >= (lastTime + 1000))
    {
        lastTime = lastFrame;
        frameCount = 0;
        count++;
    }

    while (running)
    {
        render();
        input();
        update();
    }

    if (count > 3) running = false;
}

void Game::render()
{
    SDL_SetRenderDrawColor(ren, 30, 30, 30, 255);
    SDL_Rect rect;
    rect.x = rect.y = 0;
    rect.w = 1000;
    rect.h = 600;
    SDL_RenderFillRect(ren, &rect);

    f1.placeIt(ren);
    f2.placeIt(ren);
    f3.placeIt(ren);
    f4.placeIt(ren);
    f5.placeIt(ren);
    f6.placeIt(ren);
    f7.placeIt(ren);
    f8.placeIt(ren);
    f9.placeIt(ren);
    turn.placeIt(ren);
    Font("KOLEJ GRACZA", 510, 50, 255, 255, 255, 255);

    frameCount++;
    int timerFPS = SDL_GetTicks() - lastFrame;
    if ( timerFPS <= 1000/60 ) SDL_Delay((1000/60) - timerFPS);
    SDL_RenderPresent(ren);
}

void Game::input()
{
    SDL_Rect mouse;
    mouse.h = 1;
    mouse.w = 1;
    int x, y;
    SDL_Event e;
    while ( SDL_PollEvent(&e) )
    {
        if (e.type == SDL_QUIT) running = false;
        SDL_GetMouseState(&mouse.x, &mouse.y);
        if(SDL_HasIntersection(&f1.o.dest, &mouse))
        {
            SDL_SetCursor(SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_HAND));
            if (e.type == SDL_MOUSEBUTTONDOWN & e.button.button == SDL_BUTTON_LEFT & f1.state == 'n')
            {
                f1.change(turn.state);
                turn.change();
            } 
        }
        else if(SDL_HasIntersection(&f2.o.dest, &mouse))
        {
            SDL_SetCursor(SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_HAND));
            if (e.type == SDL_MOUSEBUTTONDOWN & e.button.button == SDL_BUTTON_LEFT & f2.state == 'n')
            {
                f2.change(turn.state);
                turn.change();
            } 
        }
        else if(SDL_HasIntersection(&f3.o.dest, &mouse))
        {
            SDL_SetCursor(SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_HAND));
            if (e.type == SDL_MOUSEBUTTONDOWN & e.button.button == SDL_BUTTON_LEFT & f3.state == 'n')
            {
                f3.change(turn.state);
                turn.change();
            } 
        }
        else if(SDL_HasIntersection(&f4.o.dest, &mouse))
        {
            SDL_SetCursor(SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_HAND));
            if (e.type == SDL_MOUSEBUTTONDOWN & e.button.button == SDL_BUTTON_LEFT & f4.state == 'n')
            {
                f4.change(turn.state);
                turn.change();
            } 
        }
        else if(SDL_HasIntersection(&f5.o.dest, &mouse))
        {
            SDL_SetCursor(SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_HAND));
            if (e.type == SDL_MOUSEBUTTONDOWN & e.button.button == SDL_BUTTON_LEFT & f5.state == 'n')
            {
                f5.change(turn.state);
                turn.change();
            } 
        }
        else if(SDL_HasIntersection(&f6.o.dest, &mouse))
        {
            SDL_SetCursor(SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_HAND));
            if (e.type == SDL_MOUSEBUTTONDOWN & e.button.button == SDL_BUTTON_LEFT & f6.state == 'n')
            {
                f6.change(turn.state);
                turn.change();
            } 
        }
        else if(SDL_HasIntersection(&f7.o.dest, &mouse))
        {
            SDL_SetCursor(SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_HAND));
            if (e.type == SDL_MOUSEBUTTONDOWN & e.button.button == SDL_BUTTON_LEFT & f7.state == 'n')
            {
                f7.change(turn.state);
                turn.change();
            } 
        }
        else if(SDL_HasIntersection(&f8.o.dest, &mouse))
        {
            SDL_SetCursor(SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_HAND));
            if (e.type == SDL_MOUSEBUTTONDOWN & e.button.button == SDL_BUTTON_LEFT & f8.state == 'n')
            {
                f8.change(turn.state);
                turn.change();
            } 
        }
        else if(SDL_HasIntersection(&f9.o.dest, &mouse))
        {
            SDL_SetCursor(SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_HAND));
            if (e.type == SDL_MOUSEBUTTONDOWN & e.button.button == SDL_BUTTON_LEFT & f9.state == 'n')
            {
                f9.change(turn.state);
                turn.change();
            } 
        }
        else
        {
            SDL_SetCursor(SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_ARROW));
        }
        
        
        
    }
    const Uint8 *keystates = SDL_GetKeyboardState(NULL);
    if ( keystates[SDL_SCANCODE_ESCAPE] ) running = false;
}

void Game::update()
{
    if( fullscreen ) SDL_SetWindowFullscreen(win, 0);
}

void Game::Font(const char* msg, int x, int y, int r, int g, int b, int a)
{
    SDL_Surface* surf;
    SDL_Texture* tex;
    SDL_Color color;
    color.r = r;
    color.g = g;
    color.b = b;
    color.a = a;
    SDL_Rect rect;
    surf = TTF_RenderText_Solid(font, msg, color);
    tex = SDL_CreateTextureFromSurface(ren, surf);
    rect.x = x;
    rect.y = y;
    rect.h = surf -> h;
    rect.w = surf -> w;
    SDL_FreeSurface(surf);
    SDL_RenderCopy(ren, tex, NULL, &rect);
    SDL_DestroyTexture(tex);
}



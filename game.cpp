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

Game::Game()
{
    SDL_Init(0);
    SDL_CreateWindowAndRenderer(1000, 600, 0, &win, &ren);
    SDL_SetWindowTitle(win, "Kółko i krzyżyk");
    running = true;
    count = 0;
    // field.setDest(50, 50, 100, 100);
    // field.setSrc(0, 0, 100, 100);
    // field.setImg("img/nic.bmp", ren);
    loop();
}

Game::~Game()
{
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

    // field.draw(ren);
    f1.placeIt(ren);
    f2.placeIt(ren);
    f3.placeIt(ren);
    f4.placeIt(ren);
    f5.placeIt(ren);
    f6.placeIt(ren);
    f7.placeIt(ren);
    f8.placeIt(ren);
    f9.placeIt(ren);

    frameCount++;
    int timerFPS = SDL_GetTicks() - lastFrame;
    if ( timerFPS <= 1000/60 ) SDL_Delay((1000/60) - timerFPS);
    SDL_RenderPresent(ren);
}

void Game::input()
{
    SDL_Event e;
    while ( SDL_PollEvent(&e) )
    {
        if (e.type == SDL_QUIT) running = false;
    }
    const Uint8 *keystates = SDL_GetKeyboardState(NULL);
    if ( keystates[SDL_SCANCODE_ESCAPE] ) running = false;
}

void Game::update()
{
    if( fullscreen ) SDL_SetWindowFullscreen(win, 0);
}






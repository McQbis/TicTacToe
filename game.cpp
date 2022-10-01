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
Button menu(550, 400);
Menu MENU('a');
Button newGame(250, 50);
Button cont(250, 200);
Button ex(250, 350);

int timer;
bool timeStop = 1;
char str[30];
const Uint8 *keystates = SDL_GetKeyboardState(NULL);

Game::Game()
{
    SDL_Init(0);
    SDL_CreateWindowAndRenderer(1000, 600, 0, &win, &ren);
    SDL_SetWindowTitle(win, "Kółko i krzyżyk");
    TTF_Init();
    font = TTF_OpenFont("Sans.ttf", 50);
    running = true;
    count = 0;
    SDL_SetRenderDrawColor(ren, 30, 30, 30, 255);
    rect.x = rect.y = 0;
    rect.w = 1000;
    rect.h = 600;
    mouse.h = 1;
    mouse.w = 1;
    menu.o.setImg("img/menu.bmp", ren);
    newGame.o.setImg("img/nowa gra.bmp", ren);
    cont.o.setImg("img/wznow.bmp", ren);
    ex.o.setImg("img/wyjdz.bmp", ren);
    f1.o.setImg("img/nic.bmp", ren);
    f2.o.setImg("img/nic.bmp", ren);
    f3.o.setImg("img/nic.bmp", ren);
    f4.o.setImg("img/nic.bmp", ren);
    f5.o.setImg("img/nic.bmp", ren);
    f6.o.setImg("img/nic.bmp", ren);
    f7.o.setImg("img/nic.bmp", ren);
    f8.o.setImg("img/nic.bmp", ren);
    f9.o.setImg("img/nic.bmp", ren);
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

    timer = 600;

    while (running)
    {
        render();
        input();
        update();
        if (timeStop == 0) timer--;
    }

    if (count > 3) running = false;
}

void Game::render()
{
    SDL_RenderFillRect(ren, &rect);
    
    if(MENU.state != 99)
    {
        newGame.placeIt(ren);
        if (MENU.state == 'd') cont.placeIt(ren);
        ex.placeIt(ren);
    } else 
    {
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
        menu.placeIt(ren);
        Font("KOLEJ GRACZA", 510, 50, 255, 255, 255, 255);
        sprintf(str, "CZAS NA RUCH: %d", timer/60);
        Font(str, 510, 300, 255, 255, 255, 255);

        if (((f1.state == f2.state && f1.state == f3.state && f1.state != 'n') ||
            (f1.state == f5.state && f1.state == f9.state && f1.state != 'n') ||
            (f4.state == f5.state && f4.state == f6.state && f4.state != 'n') ||
            (f7.state == f5.state && f7.state == f3.state && f7.state != 'n') ||
            (f7.state == f8.state && f7.state == f9.state && f7.state != 'n') ||
            (f8.state == f5.state && f8.state == f2.state && f8.state != 'n') ||
            (f1.state == f4.state && f1.state == f7.state && f1.state != 'n') ||
            (f3.state == f6.state && f3.state == f9.state && f3.state != 'n')) || timer <= 0 )
            {
                MENU.state = 'a';
                timeStop = 1;
            }
    }

    frameCount++;
    timerFPS = SDL_GetTicks() - lastFrame;
    if ( timerFPS <= 1000/60 ) SDL_Delay((1000/60) - timerFPS);
    SDL_RenderPresent(ren);
}

void Game::input()
{

    while ( SDL_PollEvent(&e) )
    {
        if (e.type == SDL_QUIT) running = false;
        SDL_GetMouseState(&mouse.x, &mouse.y);
        if(timeStop == 0)
        {
            if(SDL_HasIntersection(&f1.o.dest, &mouse) && f1.state == 'n')
            {
                SDL_SetCursor(SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_HAND));
                if (e.type == SDL_MOUSEBUTTONDOWN & e.button.button == SDL_BUTTON_LEFT & f1.state == 'n')
                {
                    timer = 600;
                    f1.change(turn.state, ren);
                    turn.change(ren);
                } 
            }
            else if(SDL_HasIntersection(&f2.o.dest, &mouse) && f2.state == 'n')
            {
                SDL_SetCursor(SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_HAND));
                if (e.type == SDL_MOUSEBUTTONDOWN & e.button.button == SDL_BUTTON_LEFT & f2.state == 'n')
                {
                    timer = 600;
                    f2.change(turn.state, ren);
                    turn.change(ren);
                } 
            }
            else if(SDL_HasIntersection(&f3.o.dest, &mouse) && f3.state == 'n')
            {
                SDL_SetCursor(SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_HAND));
                if (e.type == SDL_MOUSEBUTTONDOWN & e.button.button == SDL_BUTTON_LEFT & f3.state == 'n')
                {
                    timer = 600;
                    f3.change(turn.state, ren);
                    turn.change(ren);
                } 
            }
            else if(SDL_HasIntersection(&f4.o.dest, &mouse) && f4.state == 'n')
            {
                SDL_SetCursor(SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_HAND));
                if (e.type == SDL_MOUSEBUTTONDOWN & e.button.button == SDL_BUTTON_LEFT & f4.state == 'n')
                {
                    timer = 600;
                    f4.change(turn.state, ren);
                    turn.change(ren);
                } 
            }
            else if(SDL_HasIntersection(&f5.o.dest, &mouse) && f5.state == 'n')
            {
                SDL_SetCursor(SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_HAND));
                if (e.type == SDL_MOUSEBUTTONDOWN & e.button.button == SDL_BUTTON_LEFT & f5.state == 'n')
                {
                    timer = 600;
                    f5.change(turn.state, ren);
                    turn.change(ren);
                } 
            }
            else if(SDL_HasIntersection(&f6.o.dest, &mouse) && f6.state == 'n')
            {
                SDL_SetCursor(SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_HAND));
                if (e.type == SDL_MOUSEBUTTONDOWN & e.button.button == SDL_BUTTON_LEFT & f6.state == 'n')
                {
                    timer = 600;
                    f6.change(turn.state, ren);
                    turn.change(ren);
                } 
            }
            else if(SDL_HasIntersection(&f7.o.dest, &mouse) && f7.state == 'n')
            {
                SDL_SetCursor(SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_HAND));
                if (e.type == SDL_MOUSEBUTTONDOWN & e.button.button == SDL_BUTTON_LEFT & f7.state == 'n')
                {
                    timer = 600;
                    f7.change(turn.state, ren);
                    turn.change(ren);
                } 
            }
            else if(SDL_HasIntersection(&f8.o.dest, &mouse) && f8.state == 'n')
            {
                SDL_SetCursor(SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_HAND));
                if (e.type == SDL_MOUSEBUTTONDOWN & e.button.button == SDL_BUTTON_LEFT & f8.state == 'n')
                {
                    timer = 600;
                    f8.change(turn.state, ren);
                    turn.change(ren);
                } 
            }
            else if(SDL_HasIntersection(&f9.o.dest, &mouse) && f9.state == 'n')
            {
                SDL_SetCursor(SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_HAND));
                if (e.type == SDL_MOUSEBUTTONDOWN & e.button.button == SDL_BUTTON_LEFT & f9.state == 'n')
                {
                    timer = 600;
                    f9.change(turn.state, ren);
                    turn.change(ren);
                } 
            }
            else if(SDL_HasIntersection(&menu.o.dest, &mouse))
            {
                SDL_SetCursor(SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_HAND));
                if (e.type == SDL_MOUSEBUTTONDOWN & e.button.button == SDL_BUTTON_LEFT)
                { 
                    MENU.state = 'd';
                    timeStop = 1;
                }
            }
            else
            {
                SDL_SetCursor(SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_ARROW));
            }
        } else {
                if (SDL_HasIntersection(&newGame.o.dest, &mouse))
                {
                    SDL_SetCursor(SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_HAND));
                    if (e.type == SDL_MOUSEBUTTONDOWN & e.button.button == SDL_BUTTON_LEFT)
                    {
                        MENU.state = 'c';
                        timeStop = 0;
                        timer = 650;
                        f1.state = 'n';
                        f2.state = 'n';
                        f3.state = 'n';
                        f4.state = 'n';
                        f5.state = 'n';
                        f6.state = 'n';
                        f7.state = 'n';
                        f8.state = 'n';
                        f9.state = 'n';
                        f1.o.setImg("img/nic.bmp", ren);
                        f2.o.setImg("img/nic.bmp", ren);
                        f3.o.setImg("img/nic.bmp", ren);
                        f4.o.setImg("img/nic.bmp", ren);
                        f5.o.setImg("img/nic.bmp", ren);
                        f6.o.setImg("img/nic.bmp", ren);
                        f7.o.setImg("img/nic.bmp", ren);
                        f8.o.setImg("img/nic.bmp", ren);
                        f9.o.setImg("img/nic.bmp", ren);
                    }
                } else if (SDL_HasIntersection(&cont.o.dest, &mouse) && MENU.state == 'd')
                {
                    SDL_SetCursor(SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_HAND));
                    if (e.type == SDL_MOUSEBUTTONDOWN & e.button.button == SDL_BUTTON_LEFT)
                    {
                        MENU.state = 'c';
                        timeStop = 0;
                    }
                } else if (SDL_HasIntersection(&ex.o.dest, &mouse))
                {
                    SDL_SetCursor(SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_HAND));
                    if (e.type == SDL_MOUSEBUTTONDOWN & e.button.button == SDL_BUTTON_LEFT)
                    {
                        SDL_Quit();
                        running = false;
                    }
                } else {
                    SDL_SetCursor(SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_ARROW));
                }
        }
    }
    if ( keystates[SDL_SCANCODE_ESCAPE] ) running = false;
}

void Game::update()
{
    if( fullscreen ) SDL_SetWindowFullscreen(win, 0);
}

void Game::Font(const char* msg, int x, int y, int r, int g, int b, int a)
{
    fontColor.r = r;
    fontColor.g = g;
    fontColor.b = b;
    fontColor.a = a;
    fontSurf = TTF_RenderText_Solid(font, msg, fontColor);
    fontTex = SDL_CreateTextureFromSurface(ren, fontSurf);
    fontRect.x = x;
    fontRect.y = y;
    fontRect.h = fontSurf -> h;
    fontRect.w = fontSurf -> w;
    SDL_FreeSurface(fontSurf);
    SDL_RenderCopy(ren, fontTex, NULL, &fontRect);
    SDL_DestroyTexture(fontTex);
}



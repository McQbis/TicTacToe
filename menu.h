#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <SDL2/SDL.h>

class Menu
{
private:
    char state;
public:
    friend class Game;
    Menu(char='a');
    ~Menu();
};

#endif //MENU_H
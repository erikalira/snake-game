#include <iostream>
#include <Windows.h>
#include "game.h"
#include <stdio.h>

int main()
{
    game g;

    g.setup();

    while (!g.gameOver) {
        g.draw();
        g.input();
        g.logic();
        Sleep(100);
    }

    return 0;
}

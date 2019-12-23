#include <iostream>
#include <Windows.h>
#include "game.h"

using namespace std;

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

#pragma once
#include <stdlib.h>
#include <iostream>
#include <conio.h>

enum eDirection { PARAR = 0, ESQ, DIR, CIMA, BAIXO };

class game
{
public:
	void setup();
	void draw();
	void input();
	void logic();
	bool gameOver;
	const int largura = 40;
	const int altura = 20;
	int x, y, frutaX, frutaY, score;
	eDirection dir;
};


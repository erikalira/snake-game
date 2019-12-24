#pragma once
#include <stdlib.h>
#include <iostream>
#include <conio.h>
#include <time.h>

class game
{
public:
	void setup();
	void draw();
	void input();
	void logic();
	bool gameOver;
	const int largura = 20;
	const int altura = 20;
	int x, y, frutaX, frutaY, score;
	enum eDirection { PARAR = 0, ESQ, DIR, CIMA, BAIXO };
	eDirection dir;
	int rabo;
	int raboX[100], raboY[100];
};


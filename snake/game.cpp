#include "game.h"

void game::setup() {
	gameOver = false;
	dir = PARAR;
	x = largura / 2;
	y = altura / 2;
	srand(time(NULL));
	frutaX = rand() % largura;
	frutaY = rand() % altura;
	score = 0;
}

void game::draw() {
	system("cls");
	for (int i = 0; i < largura+2; ++i) {
		std::cout << "#"; //linha de cima
	}
	std::cout << std::endl;

	for (int i = 0; i < altura; ++i) {
		std::cout << "#"; //linha esquerda
		for (int j = 0; j < largura; ++j) {
			if (j == x && i == y) {
				std::cout << "O"; //printa a cabe�a
			}else if (j == frutaX && i == frutaY) {
				std::cout << "F"; //printa a fruta
			}else {
				std::cout << " ";
			}
		}
		std::cout << "#" << std::endl; //linha direita
	}

	for (int i = 0; i < largura; ++i) {
		std::cout << "#"; //linha de baixo
	}
	std::cout << std::endl;
}

void game::input() {
	if (_kbhit()) {
		switch (_getch())
		{
			case 'a':
				dir = ESQ;
				break;
			case 'd':
				dir = DIR;
				break;
			case 'w':
				dir = CIMA;
				break;
			case 's':
				dir = BAIXO;
				break;
			case 'x':
				gameOver = true;
				break;
			default:
				break;
		}
	}
}

void game::logic() {
	switch (dir)
	{
		case ESQ:
			x--;
			break;
		case DIR:
			x++;
			break;
		case CIMA:
			y--;
			break;
		case BAIXO:
			y++;
			break;
		default:
			break;
	}

	if (x < 0 || x > largura-1 || y < 0 || y > altura-1 ) {
		gameOver = true;
	}

	if (x == frutaX && y == frutaY) {
		score++;
		frutaX = rand() % largura;
		frutaY = rand() % altura;
	}
}
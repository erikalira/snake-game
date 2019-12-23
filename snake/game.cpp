#include "game.h"

void game::setup() {
	gameOver = false;
	dir = PARAR;
	x = largura / 2;
	y = altura / 2;
	frutaX = rand() % largura;
	frutaY = rand() % altura;
	score = 0;
}

void game::draw() {
	system("cls");
	for (int i = 0; i < largura; ++i) {
		std::cout << "#"; //linha de cima
	}
	std::cout << std::endl;

	for (int i = 0; i < altura; ++i) {
		for (int j = 0; j < largura; ++j) {
			if (j == x && i == y) {
				std::cout << "O"; //printa a cabeça
			}else if (j == frutaX && i == frutaY) {
				std::cout << "G"; //printa a cabeça
			}
			else if (j == 0) {
				std::cout << "#"; //linha esquerda
			}else if (j == largura - 1) {
				std::cout << "#"; //linha direita
			}else {
				std::cout << " ";
			}
		}
		std::cout << std::endl;
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
}
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
	rabo = 0;
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
				std::cout << "O"; //printa a cabeça
			}else {
				bool print = false;
				for (int k = 0; k < rabo; ++k) {
					if (raboX[k] == j && raboY[k] == i) {
						std::cout << "o";
						print = true;
					}
				}
				if (!print) {
					if (j == frutaX && i == frutaY) {
						std::cout << "F"; //printa a fruta
					}
					else {
						std::cout << " ";
					}
				}
			}
		}
		std::cout << "#" << std::endl; //linha direita
	}

	for (int i = 0; i < largura; ++i) {
		std::cout << "#"; //linha de baixo
	}
	std::cout << "\n\nscore:" << score << std::endl;
}

void game::input() {
	if (_kbhit()) {
		switch (_getch())
		{
			case 'a':
				if(dir != DIR)
					dir = ESQ;
				break;
			case 'd':
				if (dir != ESQ)
					dir = DIR;
				break;
			case 'w':
				if (dir != BAIXO)
					dir = CIMA;
				break;
			case 's':
				if (dir != CIMA)
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
	if (rabo > 0) {
		for (int i = rabo - 1; i > 0; --i) {
			raboX[i] = raboX[i - 1];
			raboY[i] = raboY[i - 1];
		}
		raboX[0] = x;
		raboY[0] = y;
	}

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
		rabo++;
		frutaX = rand() % largura;
		frutaY = rand() % altura;
	}
}
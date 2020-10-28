#pragma once
#include"SetUpAndLibs.h"
#include"Level.h"

#define SIZE 20


void DrawLabyrinth(HDC hdc, Table curLabyrinth) {

	float sideLength = 4;
	HBRUSH hBrush; 
	int quaterOfElement = SIZE / 4;
	int partOfElement = SIZE / 2;

	for (auto line : curLabyrinth) {
		for (auto column : line) {

			if (column.IsEmpty()) {

				hBrush = CreateSolidBrush(RGB(255, 0, 67)); 
				SelectObject(hdc, hBrush); 
				Rectangle(hdc, column.GetPoint().second * SIZE, column.GetPoint().first * SIZE,
					column.GetPoint().second * SIZE + SIZE, column.GetPoint().first * SIZE + SIZE);
				DeleteObject(hBrush);

				switch (column.GetBounty()) {

				case DEFAULT:
					hBrush = CreateSolidBrush(RGB(193, 0, 32)); 
					SelectObject(hdc, hBrush); 
					Ellipse(hdc, column.GetPoint().second * SIZE + quaterOfElement, column.GetPoint().first * SIZE + quaterOfElement,
						column.GetPoint().second * SIZE + SIZE - quaterOfElement, column.GetPoint().first * SIZE + SIZE - quaterOfElement);
					DeleteObject(hBrush);
					break;

				case ENERGY:
					hBrush = CreateSolidBrush(RGB(0, 107, 60)); 
					SelectObject(hdc, hBrush); 
					Ellipse(hdc, column.GetPoint().second * SIZE, column.GetPoint().first * SIZE,
						column.GetPoint().second * SIZE + SIZE, column.GetPoint().first * SIZE + SIZE);
					DeleteObject(hBrush);
					break;

				case NONE:
					break;

				}

			}

			else {
				hBrush = CreateSolidBrush(RGB(255, 255, 67)); 
				SelectObject(hdc, hBrush); 
				Rectangle(hdc, column.GetPoint().second * SIZE, column.GetPoint().first * SIZE,
					column.GetPoint().second * SIZE + SIZE, column.GetPoint().first * SIZE + SIZE);
				DeleteObject(hBrush);

			}

		}

	}

}

void DrawPacman(HDC hdc, Pacman Pacman) {
	HBRUSH hBrush; 
	hBrush = CreateSolidBrush(RGB(255, 255, 0)); 
	Ellipse(hdc, Pacman.GetPoint().second * SIZE, Pacman.GetPoint().first * SIZE,
		Pacman.GetPoint().second * SIZE + SIZE, Pacman.GetPoint().first * SIZE + SIZE);
	DeleteObject(hBrush);
}

void DrawAliveEvil(HDC hdc, Level level) {
	HBRUSH hBrush; 
	hBrush = CreateSolidBrush(RGB(139, 0, 255)); 
	for (auto Evil : level.GetEvilsThatAlive()) {
		Ellipse(hdc, Evil.GetPoint().second * SIZE, Evil.GetPoint().first * SIZE,
			Evil.GetPoint().second * SIZE + SIZE, Evil.GetPoint().first * SIZE + SIZE);
	}
	DeleteObject(hBrush);
}

void DrawDeadEvil(HDC hdc, Level level) {
	HBRUSH hBrush; 
	hBrush = CreateSolidBrush(RGB(139, 0, 255)); 
	for (auto Evil : level.GetEvilsThatDead()) {
		Ellipse(hdc, Evil.GetPoint().second * SIZE, Evil.GetPoint().first * SIZE,
			Evil.GetPoint().second * SIZE + SIZE, Evil.GetPoint().first * SIZE + SIZE);
	}
	DeleteObject(hBrush);
}

void DrawEvils(HDC hdc, Level level) {
	DrawAliveEvil(hdc, level);
	DrawDeadEvil(hdc, level);
}

void DrawLifes(HDC hdc, Level level) {

	char numOfLifes[50] = { '\0' };
	char text[50] = "Lifes: ";
	_itoa_s(level.GetPacmanLifes(), numOfLifes, 10);
	strcat_s(text, numOfLifes);

	TextOutA(hdc, 30.0 * SIZE, 0.0 * SIZE, text, strlen(text));

}

void DrawScores(HDC hdc, Pacman Pacman, Level level) {

	char numOfLifes[50] = { '\0' };
	char text[50] = "Scores: ";
	_itoa_s(level.GetScores(), numOfLifes, 10);
	strcat_s(text, numOfLifes);

	TextOutA(hdc, 30.0 * SIZE, 2.0 * SIZE, text, strlen(text));

}


void Display(HDC hdc, Level level) {
	DrawLabyrinth(hdc, level.GetLabyrinth());
	DrawPacman(hdc, level.GetPacman());
	DrawEvils(hdc, level);
	DrawLifes(hdc, level);
	DrawScores(hdc, level.GetPacman(), level);
}








#include <Windows.h>
#include <iostream>
#include "GraphicsEngine.h"
using namespace std;

void GraphicsEngine::printMap(Map* map) {
	for (int i = 0; i < map->getHeight(); i++) {
		for (int j = 0; j < map->getWidth(); j++) {
			if (i == 0 || j == 0 || j == map->getWidth() - 1 || i == map->getHeight() - 1) {
				cout << map->getWallCharacter();
			}
			else {
				cout << " ";
			}
		}
		cout << endl;
	}
}

void GraphicsEngine::printSnakeElement(Point* snakeElement, char snakeCharacter) {
	goToXY(snakeElement);
	cout << snakeCharacter;
}

void GraphicsEngine::eraseSnakeElement(Point* point) {
	goToXY(point);
	cout << " ";
}

void GraphicsEngine::printScore(Score* score) {
	goToXY(score->getPosition());
	cout << score->getCharacter();

}

void GraphicsEngine::goToXY(Point* point) {
	static HANDLE h = NULL;
	if (!h)
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = { point->getX(), point->getY() };
	SetConsoleCursorPosition(h, c);
}
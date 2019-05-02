#pragma once
#include "Map.h"
#include "Snake.h"
#include "Score.h"

class GraphicsEngine
{
public:
	void printMap(Map* map);
	void printSnakeElement(Point * snakeElement, char snakeCharacter);
	void eraseSnakeElement(Point* point);
	void printScore(Score* score);
private:
	void goToXY(Point* point);
};
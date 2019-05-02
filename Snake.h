#pragma once
#include "Point.h"
#include <vector>

using namespace std;

class Snake
{
private:
	char snakeCharacter;
	vector<Point*> body;
	int size;
	int currentElementIndex = 0;

public:
	Snake(char snakeCharacter, Point* startPos, int startSize);
	void addNewPosition(Point point);
	void incrementSize();
	Point* getPosition(int index);
	int getSize();
	int getBodySize();
	int getPositionsAmmount();
	Point* getNextElement();
	void resetCurrentElementIndex();
	char getSnakeCharacter();
};
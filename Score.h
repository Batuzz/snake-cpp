#pragma once
#include "Point.h"
#include "Snake.h"
#include "Map.h"

class Score
{
private:
	Point* position;
	char scoreCharacter;
	int value;

public:
	Score(int value, char scoreCharacter);
	void setRandomPosition(Map* map, Snake* snake);
	Point* getPosition();
	char getCharacter();
};
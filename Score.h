#pragma once
#include "Point.h"
#include "Snake.h"
#include "SnakeCollisionEngine.h"
#include "Map.h"
#include <time.h>
#include <stdlib.h>

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
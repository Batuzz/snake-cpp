#pragma once
#include "AbstractCollisionEngine.h"
#include "Snake.h"

using namespace std;

class SnakeCollisionEngine : public AbstractCollisionEngine
{

private:
	Snake* snake;
	
public:
	SnakeCollisionEngine(Snake* snake);
	bool hasCollided();

};
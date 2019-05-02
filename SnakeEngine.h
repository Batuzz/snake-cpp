#pragma once
#include "GraphicsEngine.h"
#include "Map.h"
#include "ScoreCollisionEngine.h"
#include "SnakeCollisionEngine.h"
#include "WallCollisionEngine.h"
#include "AbstractController.h"
#include "Score.h"

class SnakeEngine
{
private:
	GraphicsEngine* graphicsEngine;
	Snake* snake;
	Score* score;
	Map* map;
	ScoreCollisionEngine* scoreCollisionEngine;
	SnakeCollisionEngine* snakeCollisionEngine;
	WallCollisionEngine* wallCollisionEngine;
	AbstractController* controlManager;

public:
	SnakeEngine(GraphicsEngine* graphicsEngine, Snake* snake, Score* score, Map* map, ScoreCollisionEngine* scoreCollisionEngine, SnakeCollisionEngine* snakeCollisionEngine, WallCollisionEngine* wallCollisionEngine, AbstractController* controlManager);
	void run();
};
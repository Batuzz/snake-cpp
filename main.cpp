#include "SnakeEngine.h"
#include "Map.h"
#include "GraphicsEngine.h"
#include "ScoreCollisionEngine.h"
#include "SnakeCollisionEngine.h"
#include "WallCollisionEngine.h"
#include "AbstractController.h"
#include "KeyboardController.h"
#include "Score.h"


int main()
{
	
	GraphicsEngine* graphicsEngine = new GraphicsEngine;
	Snake* snake = new Snake('o' , new Point(9, 10), 5);
	Score* score = new Score(1, (char)4);
	Map* map = new Map(100, 25, 'X');
	ScoreCollisionEngine* scoreCollisionEngine = new ScoreCollisionEngine;
	SnakeCollisionEngine* snakeCollisionEngine = new SnakeCollisionEngine(snake);
	WallCollisionEngine* wallCollisionEngine = new WallCollisionEngine(map->getWidth(), map->getHeight());
	KeyboardController* keyboardController = new KeyboardController;

	SnakeEngine* snakeEngine = new SnakeEngine(graphicsEngine, snake, score, map, scoreCollisionEngine, snakeCollisionEngine, wallCollisionEngine, keyboardController);
	snakeEngine->run();

    return 0;
}
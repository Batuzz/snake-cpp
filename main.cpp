#include "SnakeEngine.h"
#include "Map.h"
#include "GraphicsEngine.h"
#include "ScoreCollisionEngine.h"
#include "SnakeCollisionEngine.h"
#include "WallCollisionEngine.h"
#include "AbstractController.h"
#include "KeyboardController.h"
#include "Score.h"
#include "Settings.h"
#include <iostream>

int main()
{
	try {
		Settings* settings = new Settings("settings.cfg");
		settings->loadSettings();

		GraphicsEngine* graphicsEngine = new GraphicsEngine;
		Snake* snake = new Snake(settings->snakeCharacter , settings->snakeStartPosition, settings->snakeStartSize);
		Score* score = new Score(settings->scoreValue, settings->scoreCharacter);
		Map* map = new Map(settings->mapWidth, settings->mapHeight, settings->mapCharacter);
		ScoreCollisionEngine* scoreCollisionEngine = new ScoreCollisionEngine;
		SnakeCollisionEngine* snakeCollisionEngine = new SnakeCollisionEngine(snake);
		WallCollisionEngine* wallCollisionEngine = new WallCollisionEngine(map->getWidth(), map->getHeight());
		KeyboardController* keyboardController = new KeyboardController;

		SnakeEngine* snakeEngine = new SnakeEngine(graphicsEngine, snake, score, map, scoreCollisionEngine, snakeCollisionEngine, wallCollisionEngine, keyboardController, settings->speed);
		snakeEngine->run();
	} catch (const std::invalid_argument & e) {
		std::cout << e.what() << std::endl;
	}

    return 0;
}
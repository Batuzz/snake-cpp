#include "SnakeEngine.h"
#include <iostream>
#include <windows.h>

SnakeEngine::SnakeEngine(GraphicsEngine* graphicsEngine, Snake* snake, Score* score, Map* map, ScoreCollisionEngine* scoreCollisionEngine, SnakeCollisionEngine* snakeCollisionEngine, WallCollisionEngine* wallCollisionEngine, AbstractController* controlManager) {
	this->snake = snake;
	this->score = score;
	this->map = map;
	this->scoreCollisionEngine = scoreCollisionEngine;
	this->snakeCollisionEngine = snakeCollisionEngine;
	this->wallCollisionEngine = wallCollisionEngine;
	this->controlManager = controlManager;
}

void SnakeEngine::run() {
	this->graphicsEngine->printMap(this->map);
	this->score->setRandomPosition(map, snake);
	this->scoreCollisionEngine->setCurrentScorePosition(this->score->getPosition());
	this->graphicsEngine->printScore(score);

	while (true) {
		this->controlManager->prepareMove();
		this->snake->resetCurrentElementIndex();
		this->snake->addNewPosition(this->controlManager->getMove());
		this->wallCollisionEngine->setCurrentPosition(this->snake->getPosition(this->snake->getPositionsAmmount() - 1));
		this->snakeCollisionEngine->setCurrentPosition(this->snake->getPosition(this->snake->getPositionsAmmount() - 1));
		this->scoreCollisionEngine->setCurrentPosition(this->snake->getPosition(this->snake->getPositionsAmmount() - 1));

		if (this->wallCollisionEngine->hasCollided() || this->snakeCollisionEngine->hasCollided()) {
			break;
		}

		if (this->scoreCollisionEngine->hasCollided()) {
			this->score->setRandomPosition(map, snake);
			this->scoreCollisionEngine->setCurrentScorePosition(this->score->getPosition());
			this->graphicsEngine->printScore(score);
			this->snake->incrementSize();
		}

		this->graphicsEngine->printSnakeElement(this->snake->getPosition(this->snake->getPositionsAmmount() - 1), this->snake->getSnakeCharacter());
		if (snake->getSize() < snake->getBodySize()) {
			this->graphicsEngine->eraseSnakeElement(this->snake->getPosition(this->snake->getPositionsAmmount() - snake->getSize() - 1));
		}

		Sleep(500);
	}
	cout << "KONIEC";
}

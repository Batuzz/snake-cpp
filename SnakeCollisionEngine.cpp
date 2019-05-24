#include "SnakeCollisionEngine.h"


SnakeCollisionEngine::SnakeCollisionEngine(Snake* snake) {
	this->snake = snake;
}

bool SnakeCollisionEngine::hasCollided() {
	snake->resetCurrentElementIndex();
	Point* snakeElement = snake->getNextElement();
	snakeElement = snake->getNextElement();
	while (snakeElement != NULL) {
		if (*snakeElement == *this->currentPosition) {
			return true;
		}
		snakeElement = snake->getNextElement();
	}
	return false;
}

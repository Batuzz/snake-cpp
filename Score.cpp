#include "Score.h"
#include <time.h>
#include <stdlib.h>
#include "SnakeCollisionEngine.h"

Score::Score(int value, char scoreCharacter) {
	this->value = value;
	this->scoreCharacter = scoreCharacter;
	this->position = new Point();
	srand(time(NULL));
}

void Score::setRandomPosition(Map* map, Snake* snake) {

	SnakeCollisionEngine* snakeCollisionEngine = new SnakeCollisionEngine(snake);

	do {
		this->position->setX(rand() % (map->getWidth() - 2) + 1);
		this->position->setY(rand() % (map->getHeight() - 2) + 1);
		snakeCollisionEngine->setCurrentPosition(this->position);
	} while (snakeCollisionEngine->hasCollided());
}

Point* Score::getPosition() {
	return this->position;
}

char Score::getCharacter() {
	return this->scoreCharacter;
}
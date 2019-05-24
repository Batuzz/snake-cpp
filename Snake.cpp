#include "Snake.h"

#include <algorithm>
#include <iostream>

Snake::Snake(char snakeCharacter, Point* startPos, int startSize) {
	this->snakeCharacter = snakeCharacter;
	this->body.push_back(startPos);
	this->size = startSize;
}

void Snake::addNewPosition(Point point) {
	Point* currentPosition = this->getPosition(getPositionsAmmount()-1);
	body.push_back(new Point(currentPosition->getX()+point.getX(), currentPosition->getY() + point.getY()));
}

void Snake::incrementSize() {
	this->size++;
}

int Snake::getSize() {
	return this->size;
}

int Snake::getBodySize() {
	return this->body.size();
}

Point* Snake::getPosition(int index) {
	return body.at(index);
}

int Snake::getPositionsAmmount() {
	return body.size();
}

Point* Snake::getNextElement() {
	if (this->currentElementIndex < min(this->size, (int) body.size())) {
		this->currentElementIndex++;
		return body.at(body.size() - this->currentElementIndex);
	}
	return NULL;
}

void Snake::resetCurrentElementIndex() {
	this->currentElementIndex = 0;
}

char Snake::getSnakeCharacter() {
	return this->snakeCharacter;
}


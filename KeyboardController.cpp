#include "KeyboardController.h"
#include <iostream>
const char LEFT = 75;
const char RIGHT = 77;
const char UP = 72;
const char DOWN = 80;

KeyboardController::KeyboardController() {
	this->displacement = new Point(1,0);
}

void KeyboardController::prepareMove() {
	if (_kbhit()) {
		_getch();
		this->displacement = getDisplacementByChar(_getch());
	}
}

Point* KeyboardController::getDisplacementByChar(char c) {
	Point* tmpDisplacement = new Point();
	switch (c) {
		case LEFT:
			tmpDisplacement->setX(-1);
			break;
		case RIGHT:
			tmpDisplacement->setX(1);
			break;
		case UP:
			tmpDisplacement->setY(-1);
			break;
		case DOWN:
			tmpDisplacement->setY(1);
			break;
		default:
			return this->displacement;
			break;
	}
	return tmpDisplacement;
}

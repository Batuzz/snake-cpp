#include "WallCollisionEngine.h"

WallCollisionEngine::WallCollisionEngine(int width, int height) {
	this->width = width;
	this->height = height;
}
	
bool WallCollisionEngine::hasCollided() {
	return currentPosition->getX() == 0 || currentPosition->getY() == 0 || currentPosition->getX() == this->width-1 || currentPosition->getY() == this->height-1;
}

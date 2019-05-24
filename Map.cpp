#include "Map.h"


Map::Map(int width, int height, char wallCharacter) {
	this->width = width;
	this->height = height;
	this->wallCharacter = wallCharacter;
}

int Map::getWidth() {
	return this->width;
}

int Map::getHeight() {
	return this->height;
}

char Map::getWallCharacter() {
	return this->wallCharacter;
}
	

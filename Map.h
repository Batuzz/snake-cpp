#pragma once

class Map {

private:
	int width;
	int height;
	char wallCharacter;

public: 
	Map(int width, int height, char wallCharacter);
	int getWidth();
	int getHeight();
	char getWallCharacter();
};

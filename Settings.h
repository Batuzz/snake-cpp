#pragma once
#include "Point.h"
#include <string>
#include <map>
#include <fstream>
#include <iostream>

class Settings {
private:
	std::map<std::string, std::string> settings;

public:
	int speed;

	char snakeCharacter;
	Point* snakeStartPosition;
	int snakeStartSize;

	int scoreValue;
	char scoreCharacter;

	int mapWidth;
	int mapHeight;
	char mapCharacter;

	Settings(std::string settingsFileName);
	void loadSettings();
};
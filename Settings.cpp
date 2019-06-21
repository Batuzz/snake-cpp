#include "Settings.h"

Settings::Settings(std::string settingsFileName) {
	std::fstream file;
	file.open(settingsFileName, std::fstream::in);
	if (!file.is_open()) {
		throw std::invalid_argument("Could not open file " + settingsFileName);
	}

	std::string line = "";
	const std::string delimiter = " = ";
	std::string key = "";
	std::string value = "";

	while (std::getline(file, line)) {
		key = line.substr(0, line.find(delimiter));
		value = line.substr(line.find(delimiter) + delimiter.length());
		this->settings[key] = value;
	}

	file.close();
}


void Settings::loadSettings() {
	int snakeStartPositionX = std::stoi(this->settings["snakeStartPosition"].substr(0, this->settings["snakeStartPosition"].find(", ")));
	int snakeStartPositionY = std::stoi(this->settings["snakeStartPosition"].substr(this->settings["snakeStartPosition"].find(", ") + 2, this->settings["snakeStartPosition"].length()));

	this->snakeCharacter = this->settings["snakeCharacter"][0];
	this->snakeStartPosition = new Point(snakeStartPositionX, snakeStartPositionY);
	this->snakeStartSize = std::stoi(this->settings["snakeStartSize"]);

	this->scoreValue = std::stoi(this->settings["scoreValue"]);
	this->scoreCharacter = this->settings["scoreCharacter"][0];

	this->mapWidth = std::stoi(this->settings["mapWidth"]);
	this->mapHeight = std::stoi(this->settings["mapHeight"]);
	this->mapCharacter = this->settings["mapCharacter"][0];
	this->speed = std::stoi(this->settings["speed"]);
}
#pragma once
#include "Point.h"
#include "AbstractCollisionEngine.h"

class WallCollisionEngine : public AbstractCollisionEngine {

private:
	int width;
	int height;

public:
	WallCollisionEngine(int width, int height);
	bool hasCollided();
};
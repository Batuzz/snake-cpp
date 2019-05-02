#pragma once
#include "Point.h"
#include "AbstractCollisionEngine.h"

class ScoreCollisionEngine : public AbstractCollisionEngine {

private:
	Point* currentScorePosition;

public:
	bool hasCollided();
	void setCurrentScorePosition(Point* point);
};
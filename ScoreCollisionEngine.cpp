#include "ScoreCollisionEngine.h"


bool ScoreCollisionEngine::hasCollided()
{
	return *this->currentScorePosition == *this->currentPosition;
}

void ScoreCollisionEngine::setCurrentScorePosition(Point* point) {
	this->currentScorePosition = point;
}
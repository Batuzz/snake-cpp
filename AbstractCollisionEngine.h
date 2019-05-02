#pragma once
#include "Point.h"

class AbstractCollisionEngine {

protected:
	Point* currentPosition;

public:
	virtual bool hasCollided() = 0;
	void setCurrentPosition(Point* point);
};
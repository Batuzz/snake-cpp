#pragma once
#include "Point.h"

class AbstractController
{
protected:
	Point* displacement;

public:
	AbstractController();
	Point getMove();
	virtual void prepareMove() = 0;
};
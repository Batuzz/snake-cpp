#pragma once
#include "AbstractController.h"
#include <conio.h>

class KeyboardController : public AbstractController
{

public:
	KeyboardController();
	void prepareMove();
private:
	Point* getDisplacementByChar(char c);
};
#include "AbstractController.h"

AbstractController::AbstractController() {
	this->displacement = new Point();
}

Point AbstractController::getMove() {
	return *this->displacement;
}

#include "Point.h"

Point::Point(int x, int y) {
	this->x = x;
	this->y = y;
}

bool Point::operator==(Point& point) {
	return point.getX() == this->getX() && point.getY() == this->getY();
}

int Point::getX() {
	return this->x;
}

int Point::getY() {
	return this->y;
}

void Point::setX(int x) {
	this->x = x;
}

void Point::setY(int y) {
	this->y = y;
}

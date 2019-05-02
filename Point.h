#pragma once

class Point {

private:
	int x;
	int y;

public:
	Point(int x = 0, int y = 0);
	bool operator==(Point& point);
	int getX();
	int getY();
	void setX(int x);
	void setY(int y);
};
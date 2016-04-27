#pragma once

class Coordinates
{
public:

	Coordinates() : x(0), y(0) { }
	Coordinates(int x, int y) : x(x), y(y) { }

	int getX() const { return x; }
	int getY() const { return y; }

private:

	int x;
	int y;
};
#pragma once

#include "Coordinates.h"

class Level
{
public:

	Level(const std::string& fileName);
	~Level();

	//method that returns width and height
	int getWidth()const { return width; }
	int getHeight()const { return height; }

	//startPositon of player
	const Coordinates& getStartPosition() const { return startPosition; }
	int getStartX() const { return startPosition.getX(); }
	int getStartY() const { return startPosition.getY(); }

	//villianPositon of villian
	const Coordinates& getVillianPosition() const { return villianPosition; }
	int getVillianX() const { return villianPosition.getX(); }
	int getVillianY() const { return villianPosition.getY(); }

	//for later wall collisions
	bool isWall(int x, int y) const;

private:
	int width;
	int height;

	bool* levelData;
	Coordinates startPosition;
	Coordinates villianPosition;
	//Coordinates mushroomPositionArray;
};

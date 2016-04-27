#pragma once

#include "Coordinates.h"

class Level
{
public:

	Level(const std::string& fileName);
	~Level();

	//method that returns width and height
<<<<<<< HEAD
	int getWidth()const{ return width; }
	int getHeight()const{ return height; }
=======
	int getWidth()const { return width; }
	int getHeight()const { return height; }
>>>>>>> b78612e8d83eec002ba273a2fd59f9bce04bb81b

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

<<<<<<< HEAD
};

=======
};
>>>>>>> b78612e8d83eec002ba273a2fd59f9bce04bb81b

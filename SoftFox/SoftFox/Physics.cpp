#include "stdafx.h"
#include "Physics.h"


Physics::Physics()
{
}

Physics::~Physics()
{
}

///Checks for collision between two objects and returns boolean
bool Physics::isCollision(SDL_Rect& objectOne, SDL_Rect& objectTwo)
{
	///Box dimensions for objectOne
	int objectOneLeft = objectOne.x;
	int objectOneRight = objectOne.x + objectOne.w;
	int objectOneTop = objectOne.y;
	int objectOneBottom = objectOne.y + objectOne.h;

	///Box dimensions for objectTwo
	int objectTwoLeft = objectTwo.x;
	int objectTwoRight = objectTwo.x + objectTwo.w;
	int objectTwoTop = objectTwo.y;
	int objectTwoBottom = objectTwo.y + objectTwo.h;
	
	///Check if objects collide
	if (objectOneLeft < objectTwoRight && objectOneRight > objectTwoLeft && objectOneTop < objectTwoBottom && objectOneBottom > objectTwoTop)
	{
		return true;
	}
	else
	{
		return false;
	}
}
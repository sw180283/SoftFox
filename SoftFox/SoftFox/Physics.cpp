#include "stdafx.h"
#include "Physics.h"


Physics::Physics()
{
}

Physics::~Physics()
{
}

bool Physics::isCollision(SDL_Rect& objectOne, SDL_Rect& objectTwo)
{
	//check if there is a box collision between two objects
	int objectOneLeft = objectOne.x;
	int objectOneRight = objectOne.x + objectOne.w;
	int objectOneTop = objectOne.y;
	int objectOneBottom = objectOne.y + objectOne.h;

	int objectTwoLeft = objectTwo.x;
	int objectTwoRight = objectTwo.x + objectTwo.w;
	int objectTwoTop = objectTwo.y;
	int objectTwoBottom = objectTwo.y + objectTwo.h;
	
	if (objectOneLeft < objectTwoRight && objectOneRight > objectTwoLeft && objectOneTop < objectTwoBottom && objectOneBottom > objectTwoTop)
	{
		return true;
	}
	//if (objectTwoRight == objectOneLeft || objectOneRight == objectTwoLeft && objectOneBottom < objectTwoBottom || objectOneBottom  > objectTwoTop)

	else
	{
		return false;
	}
}

bool Physics::rightCollision(SDL_Rect& objectOne, SDL_Rect& objectTwo)
{
	//check if there is a box collision between two objects
	int objectOneLeft = objectOne.x;
	int objectOneRight = objectOne.x + objectOne.w;
	int objectOneTop = objectOne.y;
	int objectOneBottom = objectOne.y + objectOne.h;

	int objectTwoLeft = objectTwo.x;
	int objectTwoRight = objectTwo.x + objectTwo.w;
	int objectTwoTop = objectTwo.y;
	int objectTwoBottom = objectTwo.y + objectTwo.h;

	if (objectOneRight == objectTwoLeft && objectOneBottom < objectTwoBottom && objectOneBottom > objectTwoTop && objectOneTop < objectTwoTop && objectOneLeft < objectTwoLeft)
	{
		return true;
	}

}


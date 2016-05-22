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

bool Physics::rightCollision(SDL_Rect& objectOne1, SDL_Rect& objectTwo1)
{
	//check if there is a box collision between two objects
	int objectOneLeft1 = objectOne1.x;
	int objectOneRight1 = objectOne1.x + objectOne1.w;
	int objectOneTop1 = objectOne1.y;
	int objectOneBottom1 = objectOne1.y + objectOne1.h;

	int objectTwoLeft1 = objectTwo1.x;
	int objectTwoRight1 = objectTwo1.x + objectTwo1.w;
	int objectTwoTop1 = objectTwo1.y;
	int objectTwoBottom1 = objectTwo1.y + objectTwo1.h;

	//if (objectOneRight > objectTwoLeft && objectOneTop < objectTwoBottom && objectOneTop > objectTwoTop && objectOneLeft < objectTwoRight)
	if (objectOneLeft1 < objectTwoRight1 && objectOneRight1 > objectTwoLeft1 && objectOneTop1 < objectTwoBottom1 && objectOneBottom1 > objectTwoTop1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

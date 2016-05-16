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
	
	//if (objectOne.x < objectTwo.x + objectTwo.w && objectOne.x + objectOne.w > objectTwo.x && objectOne.y < objectTwo.y + objectTwo.h && objectOne.y + objectOne.h > objectTwo.y)
	if (objectOneLeft < objectTwoRight && objectOneRight > objectTwoLeft && objectOneTop < objectTwoBottom && objectOneBottom > objectTwoTop)
	//if (objectOneTop == objectTwoBottom || objectOneBottom == objectTwoTop)

	//if (objectTwoRight == objectOneLeft || objectOneRight == objectTwoLeft && objectOneBottom < objectTwoBottom || objectOneBottom  > objectTwoTop)
	{
		return true;
	}

	
	//if (objectOneLeft < objectTwoRight && objectOneRight > objectTwoLeft)
	
	/*
	//if (objectOne.x < objectTwo.x + objectTwo.w && objectOne.x + objectOne.w > objectTwo.x && objectOne.y < objectTwo.y + objectTwo.h && objectOne.y + objectOne.h > objectTwo.y)
	if (objectTwoLeft>objectOneLeft>objectTwoRight && objectTwoBottom>objectOneLeft>objectTwoTop || objectTwoLeft>objectOneRight>objectTwoRight && objectTwoBottom>objectOneRight>objectTwoTop)
	{
		return true;
	}
	*/

	else
	{
		return false;
	}
}
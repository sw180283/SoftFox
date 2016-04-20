#include "stdafx.h"
#include "Physics.h"


Physics::Physics()
{
}

Physics::~Physics()
{
}

SDL_bool SDL_IntersectRect(const SDL_Rect* A, const SDL_Rect* B, SDL_Rect* results);

/*
bool Physics::isCollision(SDL_Rect& objectOne, SDL_Rect& objectTwo)
{
	//check if there is a box collision between two objects
	if (objectOne.x < objectTwo.x + objectTwo.width && objectOne.x + objectOne.width > objectTwo.x && objectOne.y < objectTwo.y + objectTwo.height && objectOne.y + objectOne.height > objectTwo.y)
	{
		return true;
	}

	else
	{
		return false;
	}
}
*/
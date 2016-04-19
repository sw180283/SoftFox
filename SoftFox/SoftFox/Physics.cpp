#include "stdafx.h"
#include "Physics.h"


Physics::Physics()
{
}

bool isCollision(SDL_Rect& objectOne, SDL_Rect& objectTwo)
{
//check if there is a box collision between two objects
    if(objectOne.x < objectTwo.x + objectTwo.width && objectOne.x + objectOne.width > objectTwo.x && objectOne.y < objectTwo.y + objectTwo.height && objectOne.y + objectOne.height > objectTwo.y)
    {
        return true;
    }

    else
    {
        return false;
    }
}

Physics::~Physics()
{
}
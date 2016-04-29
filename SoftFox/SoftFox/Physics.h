#pragma once

#include "stdafx.h"
#include "Texture.h"
#include "Level.h"

class Physics
{
public:
	Physics();
	~Physics();

	bool isCollision(SDL_Rect& objectOne, SDL_Rect& objectTwo);

private:
	Level* level;
	int x;
	int y;

};


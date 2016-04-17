#pragma once

#include "resource.h"
#include "level.h"

class SoftFox
{
public:


private:
	Level* level;
	//individually draws tiles
	void drawtile(int x, int y, SDL_Texture* texture);
	//draws everything declared in level
	void drawlevel();
};


#pragma once

#include "resource.h"
#include "Level.h"
#include "Texture.h"

class SoftFox
{
public:
	SoftFox();
	~SoftFox();


private:

	SDL_Renderer* renderer;
	Level* level;
	//individually draws tiles
	void drawtile(int x, int y, SDL_Texture* texture);
	//draws everything declared in level
	void drawlevel();
};


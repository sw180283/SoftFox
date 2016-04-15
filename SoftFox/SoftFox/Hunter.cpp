//Hunter mechanic for thomas easterbrooks comp110 coding task two
#include "stdafx.h"
#include "Hunter.h"
#include "Texture.h"
#include "InitialisationError.h"

Hunter::Hunter()
{
	const int SPRITE_SIZE = 74;
	int HunterX = 400;
	int HunterY = 400;
	const int WINDOW_WIDTH = 800;
	const int WINDOW_HEIGHT = 600;

	SDL_Window* window = SDL_CreateWindow("Project Demo", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);

	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
	if (renderer == nullptr)
	{
		throw InitialisationError("SDL_CreateRenderer failed");
	}

	//setting player texture
	Texture* HunterSprite = new Texture("..\\Sprites\\red_fox_sprite_1.gif");

	//Drawing player sprite (texture class)
	HunterSprite->render(renderer, HunterX, HunterY, SPRITE_SIZE, SPRITE_SIZE);
}


Hunter::~Hunter()
{
}

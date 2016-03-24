#pragma once

#include "resource.h"
#include "Texture.h"

class SoftFox
{
public:
	SoftFox();
	~SoftFox();

	void run();

	static const int WINDOW_HEIGHT = 600;
	static const int WINDOW_WIDTH = 800;
	static const int SPRITE_SIZE = 64;
	static const int PLAYER_MOVEMENT_SPEED = 4;

	int getPlayerX() { return playerX; }
	int getPlayerY() { return playerY; }

private:
	SDL_Window* window;
	SDL_Renderer* renderer;

	Texture playerSprite;
	Texture platformSprite;

	int playerX, playerY;
	bool running;
};
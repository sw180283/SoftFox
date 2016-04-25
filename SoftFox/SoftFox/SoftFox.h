#pragma once

#include "resource.h"
#include "Texture.h"
#include "Level.h"

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

	const char* level_name = "..\\Level\\Level.txt";

	int getPlayerX() { return playerX; }
	int getPlayerY() { return playerY; }

private:
	SDL_Window* window;
	SDL_Renderer* renderer;

	SDL_Texture* playerSprite;
	SDL_Texture* platformSprite;

	Level* level;
	//individually draws tiles
	void drawTile(int x, int y, SDL_Texture* texture);
	//draws everything declared in level
	void drawLevel();

	int playerX, playerY;
	int tileSize;
	bool running;
};
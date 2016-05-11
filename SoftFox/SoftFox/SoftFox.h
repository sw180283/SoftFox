#pragma once

#include "resource.h"
#include "Level.h"
#include "Texture.h"
#include "Physics.h"
#include "Hunter.h"

class SoftFox
{
public:
	SoftFox();
	~SoftFox();

	void run();

	//Hunter (Thomas)
	int getHunterX() { return HunterX; }
	int getHunterY() { return HunterY; }

	static const int WINDOW_HEIGHT = 600;
	static const int WINDOW_WIDTH = 800;
	static const int SPRITE_SIZE = 64;
	int PLAYER_MOVEMENT_SPEED = 4;

	const char* level_name = "..\\Level\\Level_One.txt";

	int getPlayerX() { return playerX; }
	int getPlayerY() { return playerY; }
	int tileSize;

private:
	SDL_Window* window;
	SDL_Renderer* renderer;

	Texture* playerSprite;
	Texture* hunterSprite;
	Texture* mushroomSprite;
	SDL_Texture* platformSprite;
	SDL_Texture* platformSprite_Dirt;
	SDL_Texture* backgroundImage;
	

	Level* level;
	//individually draws tiles
	void drawTile(int x, int y, SDL_Texture* texture);
	//draws everything declared in level
	void drawLevel();

	Physics* physics;

	int playerX, playerY;
	int HunterX, HunterY;
	int MushroomX, MushroomY;
	bool running;
};

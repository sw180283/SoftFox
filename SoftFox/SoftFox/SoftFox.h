#pragma once

#include "resource.h"
<<<<<<< HEAD
#include "Level.h"
#include "Texture.h"
=======
#include "Texture.h"
#include "Level.h"
>>>>>>> b78612e8d83eec002ba273a2fd59f9bce04bb81b

class SoftFox
{
public:
	SoftFox();
	~SoftFox();

<<<<<<< HEAD
=======
	void run();

	static const int WINDOW_HEIGHT = 600;
	static const int WINDOW_WIDTH = 800;
	static const int SPRITE_SIZE = 64;
	static const int PLAYER_MOVEMENT_SPEED = 4;

	const char* level_name = "..\\Level\\Level_One.txt";

	int getPlayerX() { return playerX; }
	int getPlayerY() { return playerY; }
>>>>>>> b78612e8d83eec002ba273a2fd59f9bce04bb81b

private:

<<<<<<< HEAD
	SDL_Renderer* renderer;
	Level* level;
	//individually draws tiles
	void drawtile(int x, int y, SDL_Texture* texture);
	//draws everything declared in level
	void drawlevel();
};

=======
	Texture* playerSprite;
	SDL_Texture* platformSprite;
	SDL_Texture* platformSprite_dirt;
	SDL_Texture* backgroundImage;

	Level* level;
	//individually draws tiles
	void drawTile(int x, int y, SDL_Texture* texture);
	//draws everything declared in level
	void drawLevel();

	int playerX, playerY;
	int tileSize;
	bool running;
};
>>>>>>> b78612e8d83eec002ba273a2fd59f9bce04bb81b

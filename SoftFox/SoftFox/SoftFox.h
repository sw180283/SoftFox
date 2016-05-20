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
	static const int PLAYER_MOVEMENT_SPEED = 4;
	static const int gravity = 9;
	static const int upForce = gravity;
	static const int spriteAdjustmentPlayerSize = 10;
	static const int spriteAdjustmentHunterSize = 14;
	static const int spriteAdjustmentMushroomSize = 24;

	// Check keyboard state
	const Uint8* keyboardState = SDL_GetKeyboardState(nullptr);

	const char* level_name = "..\\Level\\Level_One.txt";

	int getPlayerX() { return playerX; }
	int getPlayerY() { return playerY; }
	int tileSize;

private:
	SDL_Window* window;
	SDL_Renderer* renderer;

	Texture* playerSpriteRight;
	Texture* playerSpriteLeft;
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

	//Thomas Easterbrook Coding Task two start
	void movement();
	void hasFoxTouchedHunter();
	//Thomas Easterbrook Coding Task two end
	void hasFoxTouchedPlatform();
	void jumping();

	Physics* physics;

	Uint32 start = 0;

	int playerX, playerY;
	int platformX, platformY;
	int HunterX, HunterY;
	//Thomas Easterbrook Coding Task two start
	int HunterDirection = -1;
	//Thomas Easterbrook Coding Task two end
	int MushroomX, MushroomY;
	bool running;
	bool jump;
	bool hasJumped;
	bool playerCollision;
};

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

	void run(); //Run the main game

	//Thomas Easterbrook Coding Task two start
	int getHunterX() { return hunterX; }
	int getHunterY() { return hunterY; }
	//Thomas Easterbrook Coding Task two end

	static const int WINDOW_HEIGHT = 600; ///Set the game height
	static const int WINDOW_WIDTH = 800; ///Set the game width
	static const int SPRITE_SIZE = 64;
	static const int PLAYER_MOVEMENT_SPEED = 4; ///Set default movement speed
	static const int gravity = 9; ///Gravity force on player
	static const int upForce = gravity; ///Reactive force on player
	static const int spriteAdjustmentPlayerSize = 10; ///Adjustment for player sprite to align with each platform 
	static const int spriteAdjustmentHunterSize = 14; ///Adjustment for hunter sprite to align with each platform 
	static const int spriteAdjustmentMushroomSize = 24; ///Adjustment for mushroom sprite to align with each platform 
	static const int jumpHeight = 20; ///Set player jump height
	static const int screenHeightSpriteAdjument = 40; ///Allows player to jump briefly out of game window
	static const int screenControlSpriteAdjustment = 240;

	const Uint8* keyboardState = SDL_GetKeyboardState(nullptr); // Check keyboard state

	const char* level_name = "..\\Level\\Level_Three.txt"; ///Choose level from files

	int tileSize; ///tile size uses level height and width of txt doc


private:
	SDL_Window* window;
	SDL_Renderer* renderer;

	Texture* playerSpriteRight; //player sprite faces right
	Texture* playerSpriteLeft; //player sprite faces left
	Texture* playerSprite;

	//Thomas Easterbrook Coding Task two start
	Texture* hunterSpriteRight; //player sprite faces right
	Texture* hunterSpriteLeft; //player sprite faces left
	Texture* hunterSprite;
	//Thomas Easterbrook Coding Task two end

	Texture* mushroomSprite;
	Texture* winScreen;
	Texture* controls;
	SDL_Texture* platformSprite; //player sprite with grass
	SDL_Texture* platformSprite_Dirt; //player sprite with dirt
	SDL_Texture* backgroundImage;
	
	Level* level;

	Uint32 start = 0;

	void drawTile(int x, int y, SDL_Texture* texture); 	///individually draws tile textures
	void drawLevel(); 	///draws everything in level using drawTile and txt doc
	void resetPlayer(); ///reset player position using start position in txt doc
	void playerKeyBoardCommands(); ///All player commands here
	void sideCollision();

	int playerX, playerY;
	int platformX, platformY;

	//Sam Wills Coding Task two start
	Physics* physics;

	void hasFoxTouchedPlatform(); ///Check if player is touching a platform and cancel gravity using upforce if true
	void jumping(); ///Allows player to do a single jump for a certain amount of time
	void isFoxInWindow(); ///Check if player is in game window and resets player position if not

	bool running; ///Set a boolean to keep the window running until false
	bool jump;
	bool hasJumped;
	bool playerCollision;
	//Sam Wills Coding Task two end

	//Thomas Easterbrook Coding Task two start
	void movement();
	void hasFoxTouchedHunter();
	int hunterDirection = -1;
	int hunterX, hunterY;
	//Thomas Easterbrook Coding Task two end

	//Dean Harland Coding Task two start
	int mushroomX, mushroomY;
	void endGameMushroom();
	//Dean Harland Coding Task two end
};

// SoftFox.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "SoftFox.h"
#include "InitialisationError.h"
#include "Texture.h"
#include "Level.h"

SoftFox::SoftFox()
{
	//Initialise the video to allow for display on the window
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		//If a -1 is called then the video couldn't be found such as no video card
		throw InitialisationError("SDL_Init failed");
	}

	level = new Level(level_name); //gets level from txt doc

	tileSize = WINDOW_HEIGHT / level->getHeight(); //getting tile height txt doc

	//Create the window of the program with (title, x, y, width, height, flag)
	SDL_Window* window = SDL_CreateWindow("Project Demo", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);

	//If the window returns a null
	if (window == nullptr)
	{
		//Get error message if the window isn't created
		throw InitialisationError("SDL_CreateWindow failed");
	}

	//Create a pointer to a renderer that renders in the window, in any position for the flag of syncing the frame rate of the computer for 60fps
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);

	if (renderer == nullptr)
	{
		throw InitialisationError("SDL_CreateRenderer failed");
	}

	//Load sprites locations in
	platformSprite = IMG_LoadTexture(renderer, "..\\Sprites\\platform_sprite.png");
	platformSprite_Dirt = IMG_LoadTexture(renderer, "..\\Sprites\\platform_sprite_dirt.png");
	backgroundImage = IMG_LoadTexture(renderer, "..\\Sprites\\background_art.png");
	mushroomSprite = new Texture("..\\Sprites\\mushroom.png");
	playerSpriteRight = new Texture("..\\Sprites\\foxRight.png");
	playerSpriteLeft = new Texture("..\\Sprites\\foxLeft.png");
	playerSprite = playerSpriteRight;
	//Hunter (Thomas)
	hunterSprite = new Texture("..\\Sprites\\hunter.png");
}

SoftFox::~SoftFox()
{
	//Remove all rendered objects
	if (platformSprite)
	{
		SDL_DestroyTexture(platformSprite);
	}

	if (platformSprite_Dirt)
	{
		SDL_DestroyTexture(platformSprite_Dirt);
	}

	//Remove the renderer
	SDL_DestroyRenderer(renderer);

	//Remove the window
	SDL_DestroyWindow(window);
	
	//Quit to programm running
	SDL_Quit();
}

void SoftFox::run()
{
	//Set a boolean to keep the window running until false
	running = true;

	jump = false;
	hasJumped = false;

	playerCollision = false;

	//Set player start position to the tile using level
	playerX = tileSize * level->getStartX() + tileSize / 2;
	playerY = tileSize * level->getStartY() + tileSize / 2;

	//Thomas Easterbrook Coding Task two start
	HunterX = tileSize * level->getVillianX() + tileSize/2;
	HunterY = tileSize * level->getVillianY() + tileSize/2;
	//Thomas Easterbrook Coding Task two end

	//Set mushroom start posistion to the tile using level
	MushroomX = tileSize * level->getMushroomX() + tileSize / 2;
	MushroomY = tileSize * level->getMushroomY() + tileSize / 2;

	while (running)
	{
		//Set an event
		SDL_Event ev;
		if (SDL_PollEvent(&ev))
		{
			switch (ev.type)
			{
				//Create a case for quitting the window and set running to false to deconstruct the window
				//Break or system breaks
				case SDL_QUIT:
					running = false;
					break;

				default:
					break;
			}
		}


		//Change the colour of the background renderer and then clear the colour
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);

		//Render the background first
		SDL_RenderCopy(renderer, backgroundImage, nullptr, NULL);

		//Draw the level using the method drawTile shown below
		drawLevel();

		if (keyboardState[SDL_SCANCODE_LEFT])
		{
			playerSprite = playerSpriteLeft;
			playerX -= PLAYER_MOVEMENT_SPEED;
		}

		if (keyboardState[SDL_SCANCODE_RIGHT])
		{
			playerSprite = playerSpriteRight;
			playerX += PLAYER_MOVEMENT_SPEED;
		}

		//Sam Wills coding task two start
		jumping();
		//Sam Wills coding task two end
					
		//Drawing player sprite (texture class)
		playerSprite->render(renderer, playerX, playerY, SPRITE_SIZE, SPRITE_SIZE - spriteAdjustmentPlayerSize*2);

		//Thomas Easterbrook Coding Task two start
		hunterSprite->render(renderer, HunterX, HunterY + spriteAdjustmentHunterSize, tileSize, tileSize);
		//Thomas Easterbrook Coding Task two end

		//Drawing mushroom sprite
		mushroomSprite->render(renderer, MushroomX, MushroomY + spriteAdjustmentMushroomSize, SPRITE_SIZE, SPRITE_SIZE);

		////Sam Wills coding task two start
		hasFoxTouchedPlatform();
		//Sam Wills coding task two end

		//Thomas Easterbrook Coding Task two start
		movement();
		hasFoxTouchedHunter();
		//Thomas Easterbrook Coding Task two end
					
		SDL_RenderPresent(renderer);				
	}
}

/// This method draws tiles using passed in x and y coordinates from drawLevel
void SoftFox::drawTile(int x, int y, SDL_Texture* texture) 
{
	SDL_Rect dest;
	dest.x = x* tileSize;
	dest.y = y* tileSize;
	dest.w = tileSize;
	dest.h = tileSize;
	SDL_RenderCopy(renderer, texture, nullptr, &dest);
}

//draws level to screen using drawTile and level.txt doc
void SoftFox::drawLevel()
{
	for (int y = 0; y < level->getHeight(); y++) //goes through coloumns
	{
		for (int x = 0; x < level->getWidth(); x++)//goes through rows
		{
			if (level->isWall(x, y)) //checks for wall
			{
				if (level->isWall(x,y-1) && y!=0)//if wall is above current
				{
					drawTile(x, y, platformSprite_Dirt); //no grass sprite
				}
				else
				{
					drawTile(x, y, platformSprite);// else grass
				}
			}
		}
	}
}

//Sam Wills coding task two start
///Get the collision for the player with the platform
void SoftFox::hasFoxTouchedPlatform()
{
	int playerXPos = playerX - SPRITE_SIZE / 2;
	int playerYPos = playerY + spriteAdjustmentPlayerSize;
	int playerWidth = SPRITE_SIZE / 2;
	int playerHeight = 1;
	SDL_Rect playerBox = { playerXPos, playerYPos, playerWidth, playerHeight}; //create box for player
	playerY += gravity; //set gravity for player

	for (int y = 0; y < level->getHeight(); y++) //goes through height of level txt doc for coordinate
	{
		for (int x = 0; x < level->getWidth(); x++) //goes through width of level txt doc for coordinate
		{
			if (level->isWall(x, y)) //if coordinates are wall
			{
				int platformX = tileSize * x; //translate coordinates to screen
				int platformY = tileSize * y; //translate coordinates to screen
				SDL_Rect platformBox = { platformX, platformY, tileSize, tileSize }; //create box for platform
				if (physics->isCollision(platformBox, playerBox)) //if the platform and player collide
				{
					playerY -= upForce; //show force for collision
					jump = false; //for bool jump mechanic
					hasJumped = false; //for bool jump mechanic
					playerCollision = true; //for other player detection
					return;
				}
			}
		}
	}
}

void SoftFox::jumping()
{
	//The timer starting time
	if (!jump)
	{
		if (keyboardState[SDL_SCANCODE_UP])
		{
			playerY -= 20; //make sprite move up
			start = SDL_GetTicks(); //set time to ticks
			jump = true;
		}
	}
	else if (jump && !hasJumped) //check if up is still being pressed
	{
		if (keyboardState[SDL_SCANCODE_UP])
		{
			playerY -= 20; //make sprite move up
			Uint32 jumpTime = SDL_GetTicks() - start; //set jumpTime to the time length of the jump
			if (jumpTime > 100) //if jumpTime exceeds 100
			{
				jump = false;
				hasJumped = true;
			}
		}
		else
		{
			hasJumped = true;
		}
	}
}
//Sam Wills coding task two end

//Thomas Easterbrook Coding Task two start

void SoftFox::movement()
{
	if (HunterDirection < 0) //hunter is set to minus one in header so it checks next if
	{
		if (level->isWall(HunterX / tileSize - 1, HunterY / tileSize + 1) &&
			(!level->isWall(HunterX / tileSize - 1, HunterY / tileSize))) //while the bottom left block is wall and no wall next to hunter
		{
			HunterX -= 3; //move left
		}
		else
		{
			HunterDirection = 1; // else hunter turns around
		}
	}
	else
	{
		if (level->isWall(HunterX / tileSize + 1, HunterY / tileSize + 1) &&
			(!level->isWall(HunterX / tileSize + 1, HunterY / tileSize))) // while the bottom right block is wall and no wall next to hunter
		{
			HunterX += 3; //move right
		}
		else
		{
			HunterDirection = -1; //loops hunter back to the start
		}
	}
}

bool playerTouchesFox();

void SoftFox::hasFoxTouchedHunter()
{
	SDL_Rect HunterBox = { HunterX - SPRITE_SIZE / 2, HunterY - SPRITE_SIZE / 2 + spriteAdjustmentHunterSize, SPRITE_SIZE, SPRITE_SIZE }; //creating a box relative to hunter
	SDL_Rect playerBox = { playerX - SPRITE_SIZE / 2, playerY - SPRITE_SIZE / 2, SPRITE_SIZE, SPRITE_SIZE }; //using box around the player
	if (physics -> isCollision (HunterBox, playerBox))//if they collide
	{
		playerX = tileSize * level->getStartX() + tileSize / 2;//resets player to original position
		playerY = tileSize * level->getStartY() + tileSize / 2;
	}
}
//Thomas Easterbrook Coding Task two end


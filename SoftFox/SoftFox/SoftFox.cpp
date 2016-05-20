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

	level = new Level(level_name);

	tileSize = WINDOW_HEIGHT / level->getHeight();

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
	backgroundImage = IMG_LoadTexture(renderer, "..\\Sprites\\background_art.jpg");
	mushroomSprite = new Texture("..\\Sprites\\mushroom.png");
	playerSprite = new Texture("..\\Sprites\\red_fox_sprite_1.gif");

	//Hunter (Thomas)
	hunterSprite = new Texture("..\\Sprites\\elmer.jpg");
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

	//Set hunter start position to the tile using level
	HunterX = tileSize * level->getVillianX() + tileSize/2;
	HunterY = tileSize * level->getVillianY() + tileSize/2;

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

		// Check keyboard state
		const Uint8* keyboardState = SDL_GetKeyboardState(nullptr);

		if (keyboardState[SDL_SCANCODE_LEFT])
		{
			playerX -= PLAYER_MOVEMENT_SPEED;
			/*
			if (playerCollision)
			{
				playerX += 1;
			}
			else
			{
				playerX -= PLAYER_MOVEMENT_SPEED;
			}*/

		}

		if (keyboardState[SDL_SCANCODE_RIGHT])
		{
			playerX += PLAYER_MOVEMENT_SPEED;
			/*
			if (playerCollision)
			{
				playerX += 1;
			}
			else
			{
				playerX += PLAYER_MOVEMENT_SPEED;
			}
			*/
		}


		//The timer starting time
		if (!jump)
		{
			if (keyboardState[SDL_SCANCODE_UP])
			{
				playerY -= 20;
				start = SDL_GetTicks();
				jump = true;
			}
		}
		else if (jump && !hasJumped)
		{
			if (keyboardState[SDL_SCANCODE_UP])
			{
				playerY -= 20;
				Uint32 jumpTime = SDL_GetTicks() - start;
				if (jumpTime > 100)
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


		//Change the colour of the background renderer and then clear the colour
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);

		//Render the background first
		SDL_RenderCopy(renderer, backgroundImage, nullptr, NULL);

		//Draw the level using the method drawTile shown below
		drawLevel();
					
		//Drawing player sprite (texture class)
		playerSprite->render(renderer, playerX, playerY, SPRITE_SIZE, SPRITE_SIZE);

		//Drawing hunter sprite (Thomas)
		hunterSprite->render(renderer, HunterX, HunterY, SPRITE_SIZE, SPRITE_SIZE);
		
		//Drawing mushroom sprite
		mushroomSprite->render(renderer, MushroomX, MushroomY, SPRITE_SIZE, SPRITE_SIZE);

		getCollision();

		//thomas
		movement();
		hasFoxTouchedHunter();
					
		SDL_RenderPresent(renderer);				
	}
}

void SoftFox::drawTile(int x, int y, SDL_Texture* texture)
{
	SDL_Rect dest;
	dest.x = x* tileSize;
	dest.y = y* tileSize;
	dest.w = tileSize;
	dest.h = tileSize;
	SDL_RenderCopy(renderer, texture, nullptr, &dest);
}

void SoftFox::drawLevel()
{
	for (int y = 0; y < level->getHeight(); y++)
	{
		for (int x = 0; x < level->getWidth(); x++)
		{
			if (level->isWall(x, y))
			{
				if (level->isWall(x,y-1) && y!=0)
				{
					drawTile(x, y, platformSprite_Dirt);
				}
				else
				{
					drawTile(x, y, platformSprite);
				}
			}
		}
	}
}

void SoftFox::getCollision()
{
	SDL_Rect playerBox = { playerX - SPRITE_SIZE/2, playerY - SPRITE_SIZE /2, SPRITE_SIZE/2, SPRITE_SIZE };
	playerY += gravity;

	for (int y = 0; y < level->getHeight(); y++)
	{
		for (int x = 0; x < level->getWidth(); x++)
		{
			if (level->isWall(x, y))
			{
				int platformX = tileSize * x;// + tileSize;
				int platformY = tileSize * y;// - tileSize/4;
				SDL_Rect platformBox = { platformX, platformY, tileSize, tileSize };
				if (physics->isCollision(platformBox, playerBox))
				{
					playerY -= upForce;
					jump = false;
					hasJumped = false;
					playerCollision = true;
					return;
				}
			}
		}
	}
}

//Thomas Easterbrook Coding Task two start
void SoftFox::movement()
{
	if (level->isWall(HunterX / tileSize - 1, HunterY / tileSize + 1) &&
		(!level->isWall(HunterX / tileSize - 1, HunterY / tileSize))) //while the bottom left block is wall and no wall next to hunter
	{
		HunterX -= 5; //move left
	}
	else
	{
		if (level->isWall(HunterX / tileSize + 1, HunterY / tileSize + 1) &&
			(!level->isWall(HunterX / tileSize + 1, HunterY / tileSize))) // while the bottom right block is wall and no wall next to hunter
		{
			HunterX += 5; //move right
		}
	}
}

bool playerTouchesFox();

void SoftFox::hasFoxTouchedHunter()
{
	SDL_Rect HunterBox = { HunterX - SPRITE_SIZE / 2, HunterY - SPRITE_SIZE / 2 };
	SDL_Rect playerBox = { playerX - SPRITE_SIZE / 2, playerY - SPRITE_SIZE / 2, SPRITE_SIZE, SPRITE_SIZE };
	if (physics->isCollision(HunterBox, playerBox))
	{
		playerX = tileSize * level->getStartX() + tileSize / 2;
		playerY = tileSize * level->getStartY() + tileSize / 2;
	}
}
//Thomas Easterbrook Coding Task two end


//check for wall next to hunter
//store direction he is moving if moving right but space is missing 
//new field to store direction 

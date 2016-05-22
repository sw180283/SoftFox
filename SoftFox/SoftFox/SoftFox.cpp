// SoftFox.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "SoftFox.h"
#include "InitialisationError.h"
#include "Texture.h"
#include "Level.h"

SoftFox::SoftFox()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0) //Initialise the video to allow for display on the window
	{
		throw InitialisationError("SDL_Init failed"); //If a -1 is called then the video couldn't be found such as no video card
	}

	level = new Level(level_name); //gets level from txt doc

	tileSize = WINDOW_HEIGHT / level->getHeight(); //getting tile height txt doc

	SDL_Window* window = SDL_CreateWindow("Return Home by SoftFox", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN); //Create the window of the program with (title, x, y, width, height, flag)

	if (window == nullptr) //If the window returns a null
	{
		throw InitialisationError("SDL_CreateWindow failed"); //Get error message if the window isn't created
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC); //Create a pointer to a renderer that renders in the window, in any position for the flag of syncing the frame rate of the computer for 60fps

	if (renderer == nullptr)
	{
		throw InitialisationError("SDL_CreateRenderer failed");
	}

	///Load sprites locations in
	platformSprite = IMG_LoadTexture(renderer, "..\\Sprites\\platform_sprite.png");
	platformSprite_Dirt = IMG_LoadTexture(renderer, "..\\Sprites\\platform_sprite_dirt.png");
	backgroundImage = IMG_LoadTexture(renderer, "..\\Sprites\\background_art.png");
	mushroomSprite = new Texture("..\\Sprites\\mushroom.png");
	winScreen = new Texture("..\\Sprites\\winscreen.png");
	playerSpriteRight = new Texture("..\\Sprites\\foxRight.png");
	playerSpriteLeft = new Texture("..\\Sprites\\foxLeft.png");
	playerSprite = playerSpriteRight; //Sets default sprite direction
	controls = new Texture("..\\Sprites\\controls.png");

	//Thomas Easterbrook Coding Task two start
	hunterSpriteRight = new Texture("..\\Sprites\\hunterRight.png");
	hunterSpriteLeft = new Texture("..\\Sprites\\hunterLeft.png");
	hunterSprite = hunterSpriteLeft; //Sets default sprite direction
	//Thomas Easterbrook Coding Task two end

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

	if (backgroundImage)
	{
		SDL_DestroyTexture(backgroundImage);
	}

	SDL_DestroyRenderer(renderer); //Remove the renderer
	SDL_DestroyWindow(window); //Remove the window
	SDL_Quit(); //Quit to programm running
}

void SoftFox::run()
{
	//Set all default boolean
	running = true;
	jump = false;
	hasJumped = false;
	playerCollision = false;

	resetPlayer(); 	//Sets the players position

	//Thomas Easterbrook Coding Task two start
	hunterX = tileSize * level->getVillianX() + tileSize/2;
	hunterY = tileSize * level->getVillianY() + tileSize/2;
	//Thomas Easterbrook Coding Task two end

	//Dean Harland Coding Task Two Start
	//Set mushroom start posistion to the tile using level
	mushroomX = tileSize * level->getMushroomX() + tileSize / 2;
	mushroomY = tileSize * level->getMushroomY() + tileSize / 2;
	//Dean Harland Coding Task Two End

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

		SDL_RenderCopy(renderer, backgroundImage, nullptr, NULL); //Render the background first

		drawLevel(); //Draw the level using the method drawTile shown below
		playerKeyBoardCommands();

		//Thomas Easterbrook Coding Task two start
		hunterSprite->render(renderer, hunterX, hunterY + spriteAdjustmentHunterSize, tileSize, tileSize);
		//Thomas Easterbrook Coding Task two end

		//Drawing mushroom sprite
		mushroomSprite->render(renderer, mushroomX, mushroomY + spriteAdjustmentMushroomSize, SPRITE_SIZE, SPRITE_SIZE);

		///Drawing player sprite (texture class)
		playerSprite->render(renderer, playerX, playerY, SPRITE_SIZE, playerSpriteHeight);

		//Drawing player sprite (texture class)
		controls->render(renderer, WINDOW_WIDTH - spriteControlXAdjustment, spriteControlYAdjustment, tileSize * 1.5, tileSize);

		////Sam Wills coding task two start
		jumping();
		hasFoxTouchedPlatform();
		sideCollision();
		isFoxInWindow();
		//Sam Wills coding task two end

		//Thomas Easterbrook Coding Task two start
		hunterMovement();
		hasFoxTouchedHunter();
		//Thomas Easterbrook Coding Task two end

		//Dean Harland Coding Task Two Start
		endGameMushroom();	
		//Dean Harland Coding Task Two Start

		SDL_RenderPresent(renderer);				
	}
}

///Set player start position to the tile using level
void SoftFox::resetPlayer()
{
	playerX = tileSize * level->getStartX() + tileSize / 2; //resets player to original position
	playerY = tileSize * level->getStartY() + tileSize / 2;
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

///Player keyboard movement commands
void SoftFox::playerKeyBoardCommands()
{
	///If left key pressed
	if (keyboardState[SDL_SCANCODE_LEFT])
	{
		playerSprite = playerSpriteLeft; //Change to left sprite
		playerX -= PLAYER_MOVEMENT_SPEED; //Move player left direction
	}

	if (keyboardState[SDL_SCANCODE_RIGHT])
	{
		playerSprite = playerSpriteRight; //Change to right sprite
		playerX += PLAYER_MOVEMENT_SPEED; //Move player right direction
	}
}

///draws level to screen using drawTile and level.txt doc
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

///resets player position if player outside of screen window
void SoftFox::isFoxInWindow()
{
	if (playerX > WINDOW_WIDTH || playerX < 0 || playerY > WINDOW_HEIGHT || playerY < 0 - screenHeightSpriteAdjument)
	{
		resetPlayer();
	}
}

//Sam Wills coding task two start
///Get the collision for the player with the platform
void SoftFox::hasFoxTouchedPlatform()
{
	///Set player collision box
	int playerXPos = playerX - SPRITE_SIZE / 2 + spriteAdjustmentPlayerSize;
	int playerYPos = playerY + spriteAdjustmentPlayerSize;
	int playerWidth = SPRITE_SIZE / 2;
	int playerHeight = playerSpriteGroundCollision;
	SDL_Rect playerBox = { playerXPos, playerYPos, playerWidth, playerHeight }; //create box for player

	///Set gravity for player
	playerY += gravity;

	///Find platform x,y coordinates
	for (int y = 0; y < level->getHeight(); y++) //goes through height of level txt doc for coordinate
	{
		for (int x = 0; x < level->getWidth(); x++) //goes through width of level txt doc for coordinate
		{
			if (level->isWall(x, y)) //if coordinates are wall
			{
				///Set platform collision box
				int platformX = tileSize * x; //translate coordinates to screen
				int platformY = tileSize * y; //translate coordinates to screen
				int platformWidth = tileSize;
				int platformHeight = tileSize;
				SDL_Rect platformBox = { platformX, platformY, platformWidth, platformHeight }; //create box for platform

				///Check collisions with reactive force for player Y gravity
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

///Controls reactive force for player movement left and right
void SoftFox::sideCollision()
{
	///Set player collision box
	int playerXSide = playerX - SPRITE_SIZE / 2 + spriteAdjustmentPlayerSize;
	int playerYSide = playerY + spriteAdjustmentPlayerSize;
	int playerWidthSide = SPRITE_SIZE / 2;
	int playerHeightSide = SPRITE_SIZE / 2 - spriteAdjustmentPlayerSize * 2;
	SDL_Rect playerBoxSide = { playerXSide, playerYSide, playerWidthSide, playerHeightSide }; //create box for player

	///Find platform x,y coordinates
	for (int y = 0; y < level->getHeight(); y++) //goes through height of level txt doc for coordinate
	{
		for (int x = 0; x < level->getWidth(); x++) //goes through width of level txt doc for coordinate
		{
			if (level->isWall(x, y)) //if coordinates are wall
			{
				///Set platform collision box
				int platformXSide = tileSize * x; //translate coordinates to screen
				int platformYSide = tileSize * y + platformSpriteCollisionAdjustment; //translate coordinates to screen
				int platformWidthSide = tileSize;
				int platformHeightSide = tileSize;
				SDL_Rect platformBoxSide = { platformXSide, platformYSide, platformWidthSide, platformHeightSide }; //create box for platform
				
				///Check collisions with reactive force depending on keyboard press
				if (physics->isCollision(platformBoxSide, playerBoxSide))
				{
					///Check if right pressed
					if (keyboardState[SDL_SCANCODE_RIGHT])
					{
						playerX -= PLAYER_MOVEMENT_SPEED; //move the player in left direction to cancel movement
						return;
					}
					///Check if left pressed
					else if (keyboardState[SDL_SCANCODE_LEFT])
					{
						playerX += PLAYER_MOVEMENT_SPEED; //move the player in right direction to cancel movement
						return;
					}

				}
			}
		}
	}
}

///The player can jump using the up arrow
void SoftFox::jumping()
{
	///Check if the up jump button hasn't been pressed to allow player to jump
	if (!jump)
	{
		///If up arrow pressed
		if (keyboardState[SDL_SCANCODE_UP])
		{
			playerY -= jumpHeight; //make sprite move up
			start = SDL_GetTicks(); //set time to ticks
			jump = true;
		}
	}
	///Check if the jump button is still being pressed
	else if (jump && !hasJumped)
	{
		///If up arrow pressed
		if (keyboardState[SDL_SCANCODE_UP])
		{
			playerY -= jumpHeight; //make sprite move up
			Uint32 jumpTime = SDL_GetTicks() - start; //set jumpTime to the time length of the jump
			
			///Restrict jump time to 100 milliseconds until jump reset
			if (jumpTime > 100)
			{
				jump = false; //Stop the player jumping
				hasJumped = true; //Must reset to false by platform to jump again
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
void SoftFox::hunterMovement()
{
	if (hunterDirection < 0) //hunter is set to minus one in header so it checks next if
	{
		if (level->isWall(hunterX / tileSize - 1, hunterY / tileSize + 1) && ///hunter checking walls so he can walk in that direction
			(!level->isWall(hunterX / tileSize - 1, hunterY / tileSize))) //while the bottom left block is wall and no wall next to hunter
		{
			hunterX -= 2; //move left
			hunterSprite = hunterSpriteLeft;
		}
		else
		{
			hunterDirection = 1; // else hunter turns around
		}
	}
	else
	{
		if (level->isWall(hunterX / tileSize + 1, hunterY / tileSize + 1) &&
			(!level->isWall(hunterX / tileSize + 1, hunterY / tileSize))) // while the bottom right block is wall and no wall next to hunter
		{
			hunterX += 2; //move right
			hunterSprite = hunterSpriteRight; ///change sprite to make it look like the hunter is moving in that direction
		}
		else
		{
			hunterDirection = -1; //loops hunter back to the start
		}
	}
}

void SoftFox::hasFoxTouchedHunter()
{
	SDL_Rect hunterBox = { hunterX - SPRITE_SIZE / 2, hunterY - SPRITE_SIZE / 2 + spriteAdjustmentHunterSize, SPRITE_SIZE, SPRITE_SIZE }; 
	SDL_Rect playerBox = { playerX - SPRITE_SIZE / 2, playerY - SPRITE_SIZE / 2, SPRITE_SIZE - 70, SPRITE_SIZE - 70 }; ///putting a box around the fox and hunter so that player resets on contact
	if (physics -> isCollision (hunterBox, playerBox))//if collision occurs
	{
		resetPlayer();
	}
}
//Thomas Easterbrook Coding Task two end


//Dean Harland Coding Task Two Start
void SoftFox::endGameMushroom()
{
	SDL_Rect mushroomBox = { mushroomX - SPRITE_SIZE / 2, mushroomY - SPRITE_SIZE / 2 + spriteAdjustmentMushroomSize,SPRITE_SIZE, SPRITE_SIZE };
	SDL_Rect playerBox = { playerX - SPRITE_SIZE / 2, playerY - SPRITE_SIZE / 2, SPRITE_SIZE, SPRITE_SIZE };
	if (physics->isCollision(mushroomBox, playerBox))
	{

		//render win screen
		winScreen->render(renderer, winScreenXAdjustment, winScreenYAdjustment, WINDOW_WIDTH, WINDOW_HEIGHT);
	}
}
//Dean Harland Coding Task Two End
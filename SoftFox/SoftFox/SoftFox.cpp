// SoftFox.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "SoftFox.h"
#include "InitialisationError.h"
#include "Texture.h"

SoftFox::SoftFox()
	: playerSprite("..\\Sprites\\red_fox_sprite_1.gif"),
	platformSprite("..\\Sprites\\platform_sprite.png")
{
	//Initialise the video to allow for display on the window
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		//If a -1 is called then the video couldn't be found such as no video card
		throw InitialisationError("SDL_Init failed");
	}
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
}

SoftFox::~SoftFox()
{
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
	playerX = WINDOW_WIDTH / 2;
	playerY = WINDOW_HEIGHT / 2;

	int platformX = 40;
	int platformY = 400;

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
		if (keyboardState[SDL_SCANCODE_UP])
			playerY -= PLAYER_MOVEMENT_SPEED;
		if (keyboardState[SDL_SCANCODE_DOWN])
			playerY += PLAYER_MOVEMENT_SPEED;
		if (keyboardState[SDL_SCANCODE_LEFT])
			playerX -= PLAYER_MOVEMENT_SPEED;
		if (keyboardState[SDL_SCANCODE_RIGHT])
			playerX += PLAYER_MOVEMENT_SPEED;

		//Change the colour of the background renderer and then clear the colour
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);
					
		//Drawing player sprite (texture class)
		playerSprite.render(renderer, playerX, playerY, SPRITE_SIZE, SPRITE_SIZE);
					
		//Draw platform sprite texture
		platformSprite.render(renderer, 0, platformY, WINDOW_WIDTH*2, 10);
					
		SDL_RenderPresent(renderer);				
	}
}

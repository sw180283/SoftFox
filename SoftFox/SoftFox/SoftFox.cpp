// SoftFox.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "SoftFox.h"
#include "InitialisationError.h"

const int SPRITE_SIZE = 64;
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
static const int PLAYER_MOVEMENT_SPEED = 4;

int main(int argc, char* args[])
{
	//Initialise the video to allow for display on the window
	if (SDL_Init(SDL_INIT_VIDEO) < 1)
	{
		//If a -1 is called then the video couldn't be found such as no video card
		throw InitialisationError("SDL_Init failed");
	}
	else
	{
		//Create the window of the program with (title, x, y, width, height, flag)
		SDL_Window* window = SDL_CreateWindow("Project Demo", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);

		//If the window returns a null
		if (window == nullptr)
		{
			//Get error message if the window isn't created
			throw InitialisationError("SDL_CreateWindow failed");
		}
		else
		{

			//Create a pointer to a renderer that renders in the window, in any position for the flag of syncing the frame rate of the computer for 60fps
			SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);

			if (renderer == nullptr)
			{
				throw InitialisationError("SDL_CreateRenderer failed");
			}

			//setting player texture
			SDL_Texture* playerSprite = IMG_LoadTexture(renderer, "..\\Sprites\\red_fox_sprite_1.gif");

			//setting platform texture
			SDL_Texture* platformSprite = IMG_LoadTexture(renderer, "..\\Sprites\\platform_sprite.png");

			if (playerSprite == nullptr || platformSprite == nullptr)
			{
				MessageBoxA(NULL, SDL_GetError(), "IMG_LoadTexture failed", MB_OK | MB_ICONERROR);
			}

			else
			{

				//Set a boolean to keep the window running until false
				bool running = true;
				int playerX = WINDOW_WIDTH / 2;
				int playerY = WINDOW_HEIGHT / 2;

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
					SDL_Rect dest;
					dest.x = playerX - SPRITE_SIZE / 2;
					dest.y = playerY - SPRITE_SIZE / 2;
					dest.w = SPRITE_SIZE;
					dest.h = SPRITE_SIZE;
					SDL_RenderCopy(renderer, playerSprite, nullptr, &dest);
					
					//SDL_RenderPresent(renderer);
					
					//Draw platform sprite texture
					SDL_Rect destP;
					destP.x = 0; //platformX - SPRITE_SIZE / 2;
					destP.y = platformY - SPRITE_SIZE / 2;
					destP.w = 800;// SPRITE_SIZE;
					destP.h = 10;// SPRITE_SIZE;
					SDL_RenderCopy(renderer, platformSprite, nullptr, &destP);
					
					SDL_RenderPresent(renderer);
					
				}

				//SDL_Delay(2000);

				//Remove the renderer
				SDL_DestroyRenderer(renderer);
			}
			//Remove the window
			SDL_DestroyWindow(window);
		}
		//Quit to programm running
		SDL_Quit();
	}

	return 0;
}

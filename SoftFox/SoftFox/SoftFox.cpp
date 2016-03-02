// SoftFox.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "SoftFox.h"

int main(int argc, char* args[])
{
	//Initialise the video to allow for display on the window
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		//If a -1 is called then the video couldn't be found such as no video card
		std::cout << "SDL_Init failed: " << SDL_GetError() << std::endl;
	}
	else
	{
		//Create the window of the program with (title, x, y, width, height, flag)
		SDL_Window* window = SDL_CreateWindow("Project Demo", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);

		//If the window returns a null
		if (window == nullptr)
		{
			//Get error message if the window isn't created
			std::cout << "SDL_CreateWindow failed: " << SDL_GetError() << std::endl;
		}
		else
		{
			//Create a pointer to a renderer that renders in the window, in any position for the flag of syncing the frame rate of the computer for 60fps
			SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);

			if (renderer == nullptr)
			{
				std::cout << "SDL_CreateRenderer: " << SDL_GetError() << std::endl;
			}
			else
			{

				//Set a boolean to keep the window running until false
				bool running = true;

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
					SDL_SetRenderDrawColor(renderer, 0, 0, 0, 2555);
					SDL_RenderClear(renderer);

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

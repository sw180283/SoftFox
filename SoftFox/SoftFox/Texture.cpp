#include "stdafx.h"
#include "Texture.h"
#include "InitialisationError.h"

//start the texture by passing in the fileName and initialise with a texture nullpointer
Texture::Texture(const std::string& fileName)
	: fileName(fileName), texture(nullptr)
{
}

//texture deconstructor destroys texture if the texture is true so in on screen
Texture::~Texture()
{
	if (texture)
		SDL_DestroyTexture(texture);
}

//throw error if there is no texture found
void Texture::render(SDL_Renderer* renderer, int x, int y, int width, int height)
{
	if (!texture)
	{
		//load texture using renderer with file name of type string using c style
		texture = IMG_LoadTexture(renderer, fileName.c_str());

		if (!texture)
		{
			throw InitialisationError("IMG_LoadTexture failed");
		}
	}

	//parameters for texture destination
	SDL_Rect dest;
	dest.x = x - width / 2;
	dest.y = y - height / 2;
	dest.w = width;
	dest.h = height;
	SDL_RenderCopy(renderer, texture, nullptr, &dest);
}
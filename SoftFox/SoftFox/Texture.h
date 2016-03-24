#pragma once

class Texture
{
//Pass in fileName of texture in my game
public:
	Texture(const std::string& fileName);
	~Texture();

	//sets the texture to SDL_Texture
	SDL_Texture* getTexture() { return texture; }

	void render(SDL_Renderer* renderer, int x, int y, int width, int height);

//Store fileName and texture of image privately and accessable by this class
private:
	std::string fileName;
	SDL_Texture* texture;
};


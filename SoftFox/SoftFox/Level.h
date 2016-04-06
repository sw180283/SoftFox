#pragma once
class Level
{
public:

	Level(const std::string& fileName);
	~Level();

	//method that returns width and height
	int getWidth()const{ return width; }
	int getHeight()const{ return height; }

private:
	int width;
	int height;
};


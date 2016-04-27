#pragma once
#include "stdafx.h"
#include "Level.h"

Level::Level(const std::string& fileName)
{
	//if stream allows for reading of text file
	std::ifstream levelFile(fileName);

	//vector datatype with element type string called lines
	std::vector<std::string> lines;

	//starting width of text document is 0
	width = 0;

	//run this until the end of the text document is reached
	while (!levelFile.eof())
	{
		//declare the variable line as a string
		std::string line;

		//using the std getline function extracting the field levelFile and storing them into the string line
		std::getline(levelFile, line);

		//store string of line into the vector lines
		lines.push_back(line);

		//set the width of the document to the length of the line
		if (line.length() > width)
		{
			width = line.length();
		}
	}

	//the number of rows/line stored in lines
	height = lines.size();

	//array??
	levelData = new bool[width * height];

	//iterate over y in height
	for (int y = 0; y < height; y++)
	{
		//constant reference to the string line where the vector lines is set to y position in the array
		const std::string& line = lines[y];

		//interate over x in width
		for (int x = 0; x < width; x++)
		{
			//declare textSymbol as a char
			char textSymbol;

			//when x is less than line.length
			if (x < line.length())
			{
				//textSymbol is the char in the line position x
				textSymbol = line[x];
			}

			//if the end of the line is reached, the textSymbol is blank
			else
			{
				textSymbol = ' ';
			}

			//check a series of constant expressions for each textSymbol
			switch (textSymbol)
			{
				//platform
			case 'P':
				//possibly change height and width around
				//width + x is the column position
				//y is the height
				//set levelData to true for later isWall
				levelData[y * width + x] = true;
				break;

				//player start position

			case 'S':
				//set levelData to false for later isWall
				levelData[y * width + x] = false;
				startPosition = Coordinates(x, y);
				break;


				//villian
			case'V':
				levelData[y * width + x] = false;
				villianPosition = Coordinates(x, y);
				break;

				//TO DO mushrooms


			default:
				levelData[y * width + x] = false;
				break;
			}
		}
	}
}

//deconstructor
Level::~Level()
{
	delete[] levelData;
}

//check for walls for later collisions
//if isWall return true then character cannot move through it
bool Level::isWall(int x, int y) const
{
	//if x and y inside the game window check levelData for boolean
	if (x >= 0 && x < width && y >= 0 && y < height)
	{
		return levelData[y * width + x];
	}

	//if x and y are outside of the game window
	else
	{
		return true;
	}

}


#include "stdafx.h"
#include "Level.h"


Level::Level(const std::string& fileName)
{
	//if stream allows for reading of text file
	//TO DO establish levelFile
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

			else
			{

			}
		}
	}
}


Level::~Level()
{
}

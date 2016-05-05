//Hunter mechanic for thomas easterbrooks comp110 coding task two
#include "stdafx.h"
#include "Hunter.h"
#include "Texture.h"
#include "InitialisationError.h"
#include "Level.h"

Hunter::Hunter()
{

}


Hunter::~Hunter()
{

}

int hunterX = 100; //temp
int hunterY = 100; //temp

void Hunter::movement()
{
	for (int y = 0; y < level->getHeight(); y++)
	{
		for (int x = 0; x < level->getWidth(); x++)
		{
			if (int y = hunterY + 1; int x = hunterX + 1;)
			{
				while (level->isWall(hunterY + 1, hunterX - 1))
				{
					hunterX -= 10;
					{
						if (level->isWall(hunterY + 1, hunterX - 1)) //add is not
						{
							while (level->isWall(hunterY + 1, hunterX + 1))
							{
								hunterX += 10;
							}
						}
					}
				}
			}
		}
	}
}


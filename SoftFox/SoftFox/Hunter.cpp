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

void Hunter::movement()
{
	for (int y = +1; int x = -1; )
	{
		if (level->isWall(y + 1, x - 1))
		{
			//hunter moves left
			{
				if (level->isWall(y + 1, x - 1) && !y + 1, x - 1)
				{
					//hunter moves right
					{
						if (level->isWall(y + 1, x + 1))
						{
							if (level->isWall(y + 1, x + 1) && !y + 1, x + 1)
						}
					}
				}
			}
		}
	}
}

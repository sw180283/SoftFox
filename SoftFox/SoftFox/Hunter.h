//Hunter mechanic for thomas easterbrooks comp110 coding task two
#pragma once
#include "Level.h"



class Hunter

{
public:
	Hunter();
	int HunterX;
	int HunterY;
	int movement();

	~Hunter();

private:
	Level *level;
};


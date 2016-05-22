//Hunter mechanic for thomas easterbrooks comp110 coding task two
#pragma once
#include "Level.h"


//Thomas Easterbrook Coding Task two start
class Hunter

{
public:
	Hunter();
	int hunterX;
	int hunterY;
	int movement();

	~Hunter();

private:
	Level *level;
	//Thomas Easterbrook Coding Task two end
};


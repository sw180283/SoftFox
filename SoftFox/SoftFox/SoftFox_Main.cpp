#include "stdafx.h"
#include "SoftFox_Main.h"
#include "SoftFox.h"
#include "InitialisationError.h"


int main(int argc, char* args[])
{
	try
	{
		SoftFox softfoxGame;
		softfoxGame.run();
	}

	catch (InitialisationError &err)
	{
		MessageBoxA(NULL, err.what(), "Initialisation error", MB_OK | MB_ICONERROR);
		return 1;
	}
	return 0;
}
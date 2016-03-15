#include "stdafx.h"
#include "InitialisationError.h"

//class definition which requires msg field with type string
InitialisationError::InitialisationError(const std::string& msg)
{
	//give the message passed into this class, then print the error given from SDL
	message = msg + "\n" + SDL_GetError();
}
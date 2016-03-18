#pragma once

//forward declaration of class
class InitialisationError
{
//make the class declaration public so other cpp files can access it
public:
	//the class requires a field input of msg with type string
	InitialisationError(const std::string& msg);
	const char* what() { return message.c_str(); }

//Private means this string message is only accessed from this class
private:
	std::string message;
};
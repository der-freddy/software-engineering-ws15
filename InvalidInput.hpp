#ifndef INVALIDINPUT_EXCEPTION
#define INVALIDINPUT_EXCEPTION

#include <iostream>

#include <exception>

struct InvalidInput : public std::exception
{
	const char* what() const throw()
	{
		return "Invalid input";
	}
};

#endif // INVALIDINPUT_EXCEPTION
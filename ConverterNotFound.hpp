#ifndef CONVERNOTFOUND_EXCEPTION
#define CONVERNOTFOUND_EXCEPTION

#include <iostream>

#include <exception>

struct ConverterNotFound : public std::exception
{
	const char* what() const throw()
	{
		return "Converter type not found";
	}
};

#endif // CONVERNOTFOUND_EXCEPTION
#ifndef VALUEOUTOFRANGE_EXCEPTION
#define VALUEOUTOFRANGE_EXCEPTION

#include <iostream>

#include <exception>

struct ValueOutOfRange : public std::exception
{
	const char* what() const throw()
	{
		return "Value out of range";
	}
};

#endif // VALUEOUTOFRANGE_EXCEPTION
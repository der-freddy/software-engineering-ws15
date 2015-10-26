#ifndef TEMP_CONVERTER
#define TEMP_CONVERTER
#include <string>
#include <iostream>
#include "converter.hpp"


class TempConverter : public Converter
{
public:
	//Constructor
	TempConverter();
	~TempConverter();

	virtual double convert(double inValue) = 0;
    virtual std::string toString() const = 0;
    virtual void print() const = 0;



};

#endif // TEMP_CONVERTER
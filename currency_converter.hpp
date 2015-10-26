#ifndef CURRENCY_CONVERTER
#define CURRENCY_CONVERTER
#include <string>
#include <iostream>
#include "converter.hpp"

class CurrencyConverter : public Converter
{
public:
	//Constructor
	CurrencyConverter();
	~CurrencyConverter();

	virtual double convert(double inValue) = 0;
    virtual std::string toString() const = 0;
    virtual void print() const = 0;



};

#endif // CURRENCY_CONVERTER
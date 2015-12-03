#ifndef CURRENCY_CONVERTER
#define CURRENCY_CONVERTER
#include <string>
#include <iostream>
#include "UnitConverter.hpp"

class CurrencyConverter : public UnitConverter
{
public:
	//Constructor
	CurrencyConverter();
	~CurrencyConverter();

	virtual double convert(double inValue) = 0;
    virtual std::string toString() const = 0;
    virtual void print() const = 0;


    virtual std::shared_ptr<UnitConverter> clone() = 0;
};

#endif // CURRENCY_CONVERTER
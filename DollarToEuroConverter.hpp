#ifndef DOLLARTOEUROCONVERTER_H
#define DOLLARTOEUROCONVERTER_H

#include "CurrencyConverter.hpp"

class DollarToEuroConverter : public CurrencyConverter
{
	public:
	//Constructor
	DollarToEuroConverter();
	//Constructior for chaining
	DollarToEuroConverter(std::shared_ptr<UnitConverter> converter);

	double convert(double inDollars);
	std::string toString() const;
	void print() const;

	std::shared_ptr<UnitConverter> clone();

	private:
	//decorated Converter
	std::shared_ptr<UnitConverter> _decConv;
};

#endif // DOLLARTOEUROCONVERTER_H

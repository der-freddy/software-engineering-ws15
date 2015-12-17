#include "GoldToEuroConverter.hpp"

//Constructor
GoldToEuroConverter::GoldToEuroConverter():
_decConv(nullptr)
{}

//Constructior for chaining
GoldToEuroConverter::GoldToEuroConverter(std::shared_ptr<UnitConverter> converter):
_decConv(converter)
{}

/*
	converts Celsius to Fahrenheit
	[Euro] = [Gold] * 1067.4
 	Gold value as of 28.10.15
*/

double GoldToEuroConverter::convert(double input)
{
	//check whether the converter is decorated
	if(_decConv != nullptr)
	{
		//first conversion
		input = _decConv->convert(input);
	}

	//do the remaining, second conversion
	double result = input*1067.4;

	return result;
}

std::string GoldToEuroConverter::toString() const
{
	std::string output = "Gold to Euro Converter";

	//checks whether the converter is decorated
	if(_decConv != nullptr)
	{
		output += " with decorator: " + _decConv->toString();
	}

	return output;
}

void GoldToEuroConverter::print() const
{
  std::cout << toString();
}

std::shared_ptr<UnitConverter> GoldToEuroConverter::clone()
{
	return std::make_shared<GoldToEuroConverter>();
}
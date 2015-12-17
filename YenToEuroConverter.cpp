#include "YenToEuroConverter.hpp"

//Constructor
YenToEuroConverter::YenToEuroConverter():
_decConv(nullptr)
{}

//Constructior for chaining
YenToEuroConverter::YenToEuroConverter(std::shared_ptr<UnitConverter> converter):
_decConv(converter)
{}

/*
	converts yen to euro
	
	[Euro] = [Yen] * 0.7517 * 1/100
 */

double YenToEuroConverter::convert(double input)
{
	//check whether the converter is decorated
	if(_decConv != nullptr)
	{
		//first conversion
		input = _decConv->convert(input);
	}

	//do the remaining, second conversion
	double result = input * 0.7517 * (1.0/100.0);

	return result;
}

std::string YenToEuroConverter::toString() const
{
	std::string output = "Yen to Euro Converter";

	//chechs whether the converter is decorated
	if(_decConv != nullptr)
	{
		output += " with decorator: " + _decConv->toString();
	}

	return output;
}

void YenToEuroConverter::print() const
{
	std::cout << toString();
}

std::shared_ptr<UnitConverter> YenToEuroConverter::clone()
{
	return std::make_shared<YenToEuroConverter>();
}
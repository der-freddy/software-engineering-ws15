#include "DollarToEuroConverter.hpp"

//Constructor
DollarToEuroConverter::DollarToEuroConverter():
_decConv(nullptr)
{}

//Constructior for chaining
DollarToEuroConverter::DollarToEuroConverter(std::shared_ptr<UnitConverter> converter):
_decConv(converter)
{}
/*
	converts dollar to euro
	
	[Euro] = [Dollar] * 0.88
 */

double DollarToEuroConverter::convert(double input)
{
	//check whether the converter is decorated
	if(_decConv != nullptr)
	{
		//first conversion
		input = _decConv->convert(input);
	}

	//do the remaining, second conversion
	double result = input * 0.88;

	return result;
}

std::string DollarToEuroConverter::toString() const
{
	std::string output = "Dollar to Euro Converter";

	//chechs whether the converter is decorated
	if(_decConv != nullptr)
	{
		output += " with decorator: " + _decConv->toString();
	}

	return output;
}

void DollarToEuroConverter::print() const{
  std::cout << toString();
}

std::shared_ptr<UnitConverter> DollarToEuroConverter::clone()
{
	return std::make_shared<DollarToEuroConverter>();
}
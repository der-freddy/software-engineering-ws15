#include "EuroToBritishPoundConverter.hpp"

//Constructor
EuroToBritishPoundConverter::EuroToBritishPoundConverter():
_decConv(nullptr)
{}

//Constructior for chaining
EuroToBritishPoundConverter::EuroToBritishPoundConverter(std::shared_ptr<UnitConverter> converter):
_decConv(converter)
{}

/*
	converts Euro to British Pound
	[British Pound] = [Euro] * 0.72743
*/

double EuroToBritishPoundConverter::convert(double input)
{
	//check whether the converter is decorated
	if(_decConv != nullptr)
	{
		//first conversion
		input = _decConv->convert(input);
	}

	//do the remaining, second conversion
	double result = input * 0.72743;

	return result;
}

std::string EuroToBritishPoundConverter::toString() const
{
	std::string output =  "Euro to British Pound Converter";

	//checks whether the converter is decorated
	if(_decConv != nullptr)
	{
		output += " with decorator: " + _decConv->toString();
	}

	return output;
}

void EuroToBritishPoundConverter::print() const
{
  std::cout << toString();
}

std::shared_ptr<UnitConverter> EuroToBritishPoundConverter::clone()
{
	return std::make_shared<EuroToBritishPoundConverter>();
}
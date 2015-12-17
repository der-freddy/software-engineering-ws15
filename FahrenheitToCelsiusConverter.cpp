#include "FahrenheitToCelsiusConverter.hpp"

//Constructor
FahrenheitToCelsiusConverter::FahrenheitToCelsiusConverter():
_decConv(nullptr)
{}

//Constructior for chaining
FahrenheitToCelsiusConverter::FahrenheitToCelsiusConverter(std::shared_ptr<UnitConverter> converter):
_decConv(converter)
{}

/*
	converts Fahrenheit to Celsius
	[°C] = 5/9 * ([°F] - 32)
*/

double FahrenheitToCelsiusConverter::convert(double input)
{
	//check whether the converter is decorated
	if(_decConv != nullptr)
	{
		//first conversion
		input = _decConv->convert(input);
	}

	//do the remaining, second conversion
	double result = (5.0/9.0) * (input-32);

	return (double)((int) (result*10))/10;
}

std::string FahrenheitToCelsiusConverter::toString() const
{
	return "Fahrenheit To Celsius Converter";
}

void FahrenheitToCelsiusConverter::print() const
{
	std::cout << toString();
}

std::shared_ptr<UnitConverter> FahrenheitToCelsiusConverter::clone()
{
	return std::make_shared<FahrenheitToCelsiusConverter>();
}
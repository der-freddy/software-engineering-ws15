#include "CelsiusToFahrenheitConverter.hpp"

//Constructor
CelsiusToFahrenheitConverter::CelsiusToFahrenheitConverter():
_decConv(nullptr)
{}

//Constructior for chaining
CelsiusToFahrenheitConverter::CelsiusToFahrenheitConverter(std::shared_ptr<UnitConverter> converter):
_decConv(converter)
{}

/*
	converts Celsius to Fahrenheit
	[°F] = 9/5 * ([°C] + 32)
*/

double CelsiusToFahrenheitConverter::convert(double input)
{
	//check whether the converter is decorated
	if(_decConv != nullptr)
	{
		//first conversion
		input = _decConv->convert(input)
	}

	double result = (9.0/5.0) * (input+32);

	return (double)((int) (result*10))/10;

}

std::string CelsiusToFahrenheitConverter::toString() const
{
	return "Celsius To Fahrenheit Converter";
}

void CelsiusToFahrenheitConverter::print() const
{
	std::cout << toString();
}

std::shared_ptr<UnitConverter> CelsiusToFahrenheitConverter::clone()
{
	return std::make_shared<CelsiusToFahrenheitConverter>();
}
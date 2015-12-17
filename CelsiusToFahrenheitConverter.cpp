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
	[°F] = 9/5 * [°C] + 32
*/

double CelsiusToFahrenheitConverter::convert(double input)
{
	//check whether the converter is decorated
	if(_decConv != nullptr)
	{
		//first conversion
		input = _decConv->convert(input);
	}

	//do the remaining, second conversion
	double result = (9.0/5.0) * input + 32;

	return (double)((int) (result*10))/10;
}

std::string CelsiusToFahrenheitConverter::toString() const
{
	std::string output = "Celsius To Fahrenheit Converter";

	//chechs whether the converter is decorated
	if(_decConv != nullptr)
	{
		output += " with decorator: " + _decConv->toString();
	}

	return output;
}

void CelsiusToFahrenheitConverter::print() const
{
	std::cout << toString();
}

std::shared_ptr<UnitConverter> CelsiusToFahrenheitConverter::clone()
{	
	/*
	Does not work the way i want it to...

	//chechs whether the converter is decorated
	if(_decConv != nullptr)
	{
		return std::make_shared<CelsiusToFahrenheitConverter>(std::make_shared<UnitConverter>);
	}
	else
	{
		return std::make_shared<CelsiusToFahrenheitConverter>();
	}
	*/

	return std::make_shared<CelsiusToFahrenheitConverter>();
}
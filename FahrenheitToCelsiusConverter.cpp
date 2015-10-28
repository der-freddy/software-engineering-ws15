#include "FahrenheitToCelsiusConverter.hpp"

	//Constructor
	FahrenheitToCelsiusConverter::FahrenheitToCelsiusConverter()
	{}
	FahrenheitToCelsiusConverter::~FahrenheitToCelsiusConverter()
	{}

	double FahrenheitToCelsiusConverter::convert(double inValue)
	{
		return (inValue-32)*(5/9);
	}

	std::string FahrenheitToCelsiusConverter::toString() const
	{
		return "Fahrenheit To Celsius Converter";
	}
    void FahrenheitToCelsiusConverter::print() const
    {
    	std::cout << toString();
    }


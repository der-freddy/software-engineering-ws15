#include "FahrenheitToCelsiusConverter.hpp"

	//Constructor
	FahrenheitToCelsiusConverter::FahrenheitToCelsiusConverter()
	{}
	FahrenheitToCelsiusConverter::~FahrenheitToCelsiusConverter()
	{}

	double FahrenheitToCelsiusConverter::convert(double inValue)
	{
		double tmp = (inValue-32)*(5.0/9.0);
		

		return (double)((int) (tmp*10))/10;
		
	}

	std::string FahrenheitToCelsiusConverter::toString() const
	{
		return "Fahrenheit To Celsius Converter";
	}
    void FahrenheitToCelsiusConverter::print() const
    {
    	std::cout << toString();
    }


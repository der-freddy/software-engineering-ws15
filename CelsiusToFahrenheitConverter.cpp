#include "CelsiusToFahrenheitConverter.hpp"

	//Constructor
	CelsiusToFahrenheit::CelsiusToFahrenheit();
	CelsiusToFahrenheit::~CelsiusToFahrenheit();

	double CelsiusToFahrenheit::convert(double inValue)
	{
		return inValue*1.8+32;
	}

	std::string CelsiusToFahrenheit::toString() const
	{
		return "Celsius To Fahrenheit Converter"
	}
    void CelsiusToFahrenheit::print() const
    {
    	std::cout << toString();
    }


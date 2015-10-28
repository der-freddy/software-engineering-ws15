#include "CelsiusToFahrenheitConverter.hpp"

	//Constructor
	CelsiusToFahrenheit::CelsiusToFahrenheit();
	CelsiusToFahrenheit::~CelsiusToFahrenheit();

	double CelsiusToFahrenheit::convert(double inValue)
	{
		return (inValue-32)*(5/9);
	}

	std::string CelsiusToFahrenheit::toString() const
	{
		return "Fahrenheit To Celsius Converter";
	}
    void CelsiusToFahrenheit::print() const
    {
    	std::cout << toString();
    }


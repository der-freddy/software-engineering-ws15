#include "CelsiusToFahrenheitConverter.hpp"

	//Constructor
	CelsiusToFahrenheitConverter::CelsiusToFahrenheitConverter()
	{}
	CelsiusToFahrenheitConverter::~CelsiusToFahrenheitConverter()
	{}

	double CelsiusToFahrenheitConverter::convert(double inValue)
	{
		double tmp = (inValue*1.8)+32;

		return (double)((int) (tmp*10))/10;

	}

	std::string CelsiusToFahrenheitConverter::toString() const
	{
		return "Celsius To Fahrenheit Converter";
	}
    void CelsiusToFahrenheitConverter::print() const
    {
    	std::cout << toString();
    }

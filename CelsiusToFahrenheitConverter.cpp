#include "CelsiusToFahrenheitConverter.hpp"

	//Constructor
	CelsiusToFahrenheitConverter::CelsiusToFahrenheitConverter()
	{}
	CelsiusToFahrenheitConverter::~CelsiusToFahrenheitConverter()
	{}

	double CelsiusToFahrenheitConverter::convert(double inValue)
	{
		return inValue*1.8+32;
	}

	std::string CelsiusToFahrenheitConverter::toString() const
	{
		return "Celsius To Fahrenheit Converter";
	}
    void CelsiusToFahrenheitConverter::print() const
    {
    	std::cout << toString();
    }


#ifndef CtoF
#define CtoF
#include <string>
#include <iostream>
#include "TempConverter.hpp"

class CelsiusToFahrenheitConverter : public TempConverter
{
	public:
		//Constructor
		CelsiusToFahrenheitConverter();
		~CelsiusToFahrenheitConverter();

		double convert(double inValue) override;
	    std::string toString() const override;
    	void print() const override;

};


#endif
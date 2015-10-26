#ifndef CtoF
#define CtoF
#include <string>
#include <iostream>
#include "converter.hpp"

class CelsiusToFahrenheit : public TempConverter
{
	public:
		//Constructor
		CelsiusToFahrenheit();
		~CelsiusToFahrenheit();

		double convert(double inValue) override;
	    std::string toString() const override;
    	void print() const override;

};


#endif
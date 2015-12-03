#ifndef FtoC
#define FtoC
#include <string>
#include <iostream>
#include "TempConverter.hpp"

class FahrenheitToCelsiusConverter : public TempConverter
{
	public:
		//Constructor
		FahrenheitToCelsiusConverter();
		~FahrenheitToCelsiusConverter();

		double convert(double inValue) override;
	    std::string toString() const override;
    	void print() const override;

	    std::shared_ptr<UnitConverter> clone();
};


#endif
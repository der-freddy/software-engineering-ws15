#ifndef FtoC
#define FtoC
#include <string>
#include <iostream>
#include "converter.hpp"

class FahrenheitToCelsius : public TempConverter
{
	public:
		//Constructor
		FahrenheitToCelsius();
		~FahrenheitToCelsius();

		double convert(double inValue) override;
	    std::string toString() const override;
    	void print() const override;

};


#endif
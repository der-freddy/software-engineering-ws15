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
		//Constructior for chaining
		FahrenheitToCelsiusConverter(std::shared_ptr<UnitConverter> converter);

		double convert(double inValue) override;
		std::string toString() const override;
		void print() const override;

		std::shared_ptr<UnitConverter> clone();

	private:
		//decoratedConverter
		std::shared_ptr<UnitConverter> _decConv;
};


#endif
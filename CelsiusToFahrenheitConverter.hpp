#ifndef CtoF
#define CtoF

#include "TempConverter.hpp"

class CelsiusToFahrenheitConverter : public TempConverter
{
	public:
	//Constructor
	CelsiusToFahrenheitConverter();
	//Constructior for chaining
	CelsiusToFahrenheitConverter(std::shared_ptr<UnitConverter> converter);

	double convert(double inValue) override;
	std::string toString() const override;
	void print() const override;

	std::shared_ptr<UnitConverter> clone();

	private:
	//decorated Converter
	std::shared_ptr<UnitConverter> _decConv;
};

#endif
#ifndef EUROTOBRIISHPOUNDCONVERTER
#define EUROTOBRIISHPOUNDCONVERTER

#include "CurrencyConverter.hpp"

class EuroToBritishPoundConverter : public CurrencyConverter
{
	public:
	//Constructor
	CelsiusToFahrenheitConverter();
	//Constructior for chaining
	CelsiusToFahrenheitConverter(std::shared_ptr<UnitConverter> converter);

    double convert(double currency);
    std::string toString() const;
    void print() const;

    std::shared_ptr<UnitConverter> clone();

    private:
	//decorated Converter
	std::shared_ptr<UnitConverter> _decConv;
};

#endif // EUROTOBRITISHPOUND
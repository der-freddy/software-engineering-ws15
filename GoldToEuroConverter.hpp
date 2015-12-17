#ifndef GOLDTHOEUROCONVERTER
#define GOLDTHOEUROCONVERTER

#include "CurrencyConverter.hpp"

class GoldToEuroConverter : public CurrencyConverter
{
  public:
  	//Constructor
	GoldToEuroConverter();
	//Constructior for chaining
	GoldToEuroConverter(std::shared_ptr<UnitConverter> converter);

    double convert(double inputGold);
    std::string toString() const;
    void print() const;

    std::shared_ptr<UnitConverter> clone();

	private:
	//decorated Converter
	std::shared_ptr<UnitConverter> _decConv;
};

#endif // GOLDTHOEUROCONVERTER

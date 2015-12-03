#ifndef GOLDTHOEUROCONVERTER
#define GOLDTHOEUROCONVERTER

#include "CurrencyConverter.hpp"

class GoldToEuroConverter : public CurrencyConverter
{
  public:
    GoldToEuroConverter();
    ~GoldToEuroConverter();
    double convert(double inputGold);
    std::string toString() const;
    void print() const;

    std::shared_ptr<UnitConverter> clone();
};

#endif // GOLDTHOEUROCONVERTER

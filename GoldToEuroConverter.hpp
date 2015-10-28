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
};

#endif // GOLDTHOEUROCONVERTER

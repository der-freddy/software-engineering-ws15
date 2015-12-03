#ifndef DOLLARTOEUROCONVERTER_H
#define DOLLARTOEUROCONVERTER_H

#include "CurrencyConverter.hpp"
#include <string>

class DollarToEuroConverter : public CurrencyConverter
{
  public:
    DollarToEuroConverter();
    ~DollarToEuroConverter();
    double convert(double inDollars);
    std::string toString() const;
    void print() const;

    std::shared_ptr<UnitConverter> clone();
};

#endif // DOLLARTOEUROCONVERTER_H

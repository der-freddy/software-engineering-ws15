#ifndef DOLLARTOEUROCONVERTER_H
#define DOLLARTOEUROCONVERTER_H

#include "CurrencyConverter.hpp"

class dollarToEuroConverter : public CurrencyConverter
{
  public:
    dollarToEuroConverter();
    ~dollarToEuroConverter();
    double convert(double inDollars);
    std::string toString() const;
    void print() const;
};

#endif // DOLLARTOEUROCONVERTER_H

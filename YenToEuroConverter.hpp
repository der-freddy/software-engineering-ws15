#ifndef YENTOEUROCONVERTER_H
#define YENTOEUROCONVERTER_H

#include "CurrencyConverter.hpp"

class YenToEuroConverter : public CurrencyConverter
{
  public:
    YenToEuroConverter();
    double convert(double inDollars);
    std::string toString() const;
    void print() const;
};

#endif // DOLLARTOEUROCONVERTER_H

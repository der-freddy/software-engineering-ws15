#ifndef YENTOEUROCONVERTER_H
#define YENTOEUROCONVERTER_H

#include "converter.hpp"

class dollarToEuroConverter : public Converter
{
  public:
    yenToEuroConverter();
    double convert(double inDollars);
    std::string toString() const;
    void print() const;
};

#endif // DOLLARTOEUROCONVERTER_H

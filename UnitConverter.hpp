#ifndef UNITCONVERTER_H
#define UNITCONVERTER_H

#include <iostream>
#include <string>

class UnitConverter
{
  public:
    UnitConverter();
	virtual ~UnitConverter();
    virtual double convert(double inValue) = 0;
    virtual std::string toString() const;
    virtual void print() const = 0;
};

#endif // UNITCONVERTER_H
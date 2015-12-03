#ifndef UNITCONVERTER_H
#define UNITCONVERTER_H

#include <iostream>
#include <string>

//for pointer..ish things
#include <memory>

class UnitConverter
{
  public:
    UnitConverter();
	virtual ~UnitConverter();
    virtual double convert(double inValue) = 0;
    virtual std::string toString() const;
    virtual void print() const = 0;

    virtual std::shared_ptr<UnitConverter> clone() = 0;
};

#endif // UNITCONVERTER_H
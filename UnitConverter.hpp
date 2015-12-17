#ifndef UNITCONVERTER_H
#define UNITCONVERTER_H

#include <iostream>
#include <string>

//for pointer..ish things
#include <memory>

class UnitConverter
{
  public:

    //Constructor
    UnitConverter();

    //Destructor
	virtual ~UnitConverter();
    
	//"primary" method
    virtual double convert(double inValue) = 0;
	
	//clone method for factory
    virtual std::shared_ptr<UnitConverter> clone() = 0;

    //print methods
    virtual std::string toString() const = 0;
    virtual void print() const = 0;

};

#endif // UNITCONVERTER_H
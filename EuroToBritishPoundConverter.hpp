#ifndef EUROTOBRIISHPOUNDCONVERTER
#define EUROTOBRIISHPOUNDCONVERTER

#include "CurrencyConverter.hpp"

class EuroToBritishPoundConverter : public CurrencyConverter
{
  public:
    EuroToBritishPoundConverter();
    ~EuroToBritishPoundConverter();
    double convert(double currency);
    std::string toString() const;
    void print() const;

    std::shared_ptr<UnitConverter> clone();
};

#endif // EUROTOBRITISHPOUND
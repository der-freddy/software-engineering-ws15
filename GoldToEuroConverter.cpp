#include "GoldToEuroConverter.hpp"

#include <string>
#include <cmath>
GoldToEuroConverter::GoldToEuroConverter()
{}
GoldToEuroConverter::~GoldToEuroConverter()
{}

/*In: Gold ounce
 *Out: Euro value of input Euro as of 28.10.15
 */
double GoldToEuroConverter::convert(double inputGold)
{
  return inputGold*1067.4;
}

std::string GoldToEuroConverter::toString() const
{
  return "Gold to Euro Converter";
}

void GoldToEuroConverter::print() const
{
  std::cout << toString();
}

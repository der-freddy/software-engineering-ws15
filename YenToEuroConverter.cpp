#include "YenToEuroConverter.hpp"

#include <string>
#include <cmath>
YenToEuroConverter::YenToEuroConverter()
{
}

/*In: double value of dollars
 *Out: Euro value of input dollars as of 9.10.15
 */
double YenToEuroConverter::convert(double inputDollars){
  return inputDollars*0.7517*pow(10,-2);
}

std::string YenToEuroConverter::toString() const{
  return "Yen to Euro Converter";
}

void YenToEuroConverter::print() const{
  std::cout << toString();
}

#include "dollartoeuroconverter.hpp"

#include <string>
#include <cmath>
dollarToEuroConverter::dollarToEuroConverter()
{
}

/*In: double value of dollars
 *Out: Euro value of input dollars as of 9.10.15
 */
double yenToEuroConverter::convert(double inputDollars){
  return inputDollars*0.7517*pow(10,-2);
}

std::string yenToEuroConverter::toString() const{
  return "Yen to Euro Converter";
}

void yenToEuroConverter::print() const{
  std::cout << toString();
}

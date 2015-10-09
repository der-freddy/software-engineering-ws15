#include "dollartoeuroconverter.hpp"

#include <string>

dollarToEuroConverter::dollarToEuroConverter()
{
}

/*In: double value of dollars
 *Out: Euro value of input dollars as of 19.10.14
 */
double dollarToEuroConverter::convert(double inputDollars){
  return inputDollars*0.88;
}

std::string dollarToEuroConverter::toString() const{
  return "Dollar to Euro Converter";
}

void dollarToEuroConverter::print() const{
  std::cout << this->toString();
}

#include "DollarToEuroConverter.hpp"

#include <string>

DollarToEuroConverter::DollarToEuroConverter()
{
}

DollarToEuroConverter::~DollarToEuroConverter()
{
}

/*In: double value of Dollars
 *Out: Euro value of input Dollars as of 9.10.15
 */
double DollarToEuroConverter::convert(double inputDollars){
  return inputDollars*0.88;
}

std::string DollarToEuroConverter::toString() const{
  return "Dollar to Euro Converter";
}

void DollarToEuroConverter::print() const{
  std::cout << toString();
}

std::shared_ptr<UnitConverter> DollarToEuroConverter::clone()
{
	return std::make_shared<DollarToEuroConverter>();
}
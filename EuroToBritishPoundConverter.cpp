#include "EuroToBritishPoundConverter.hpp"

#include <string>
#include <cmath>

EuroToBritishPoundConverter::EuroToBritishPoundConverter()
{}
EuroToBritishPoundConverter::~EuroToBritishPoundConverter()
{}

/*In: Euro value
 *Out: British Pound value of input Euro as of 17.12.15
 */
double EuroToBritishPoundConverter::convert(double inputEuro)
{
  return inputEuro*0.72743;
}

std::string EuroToBritishPoundConverter::toString() const
{
  return "Euro to British Pound Converter";
}

void EuroToBritishPoundConverter::print() const
{
  std::cout << toString();
}

std::shared_ptr<UnitConverter> EuroToBritishPoundConverter::clone()
{
	return std::make_shared<EuroToBritishPoundConverter>();
}
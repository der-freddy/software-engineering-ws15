#include "YenToEuroConverter.hpp"

#include <string>
#include <cmath>

YenToEuroConverter::YenToEuroConverter()
{}

YenToEuroConverter::~YenToEuroConverter()
{}


/*In: double value of Yen
 *Out: Euro value of input yen as of 28.10.15
 */
double YenToEuroConverter::convert(double inputYen)
{
	return inputYen*0.7517*pow(10,-2);
}

std::string YenToEuroConverter::toString() const
{
	return "Yen to Euro Converter";
}

void YenToEuroConverter::print() const
{
	std::cout << toString();
}

std::shared_ptr<UnitConverter> YenToEuroConverter::clone()
{
	return std::make_shared<YenToEuroConverter>();
}
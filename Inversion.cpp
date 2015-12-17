#include "Inversion.hpp"
//#include "temperatureconverter.hpp"

Inversion::Inversion():
_decConv{nullptr}
{}

Inversion::Inversion(std::shared_ptr<UnitConverter> converter)
{
	//there need to be some typesafety features
	_decConv = converter;
}

ConverterPtr Inversion::clone() const {
	return std::make_shared<Inversion>();
}

double Inversion::convert(double inValue)
{
	double result;

	if(_decConv != nullptr)
	{
		inValue_ = inValue;
		result = inValue / pdConverter_->convert(1.0);
	}

	return result;
}

std::string Inversion::toString() const
{
	return "Inversion has inverted ";
}

void Inversion::print() const
{
	std::cout << toString();
}
#include "Inversion.hpp"
//#include "temperatureconverter.hpp"

Inversion::Inversion():
_decConv{nullptr}
{}

Inversion::Inversion(std::shared_ptr<UnitConverter> converter)
{
	//some typesafety
	if((converter->toString() == "Fahrenheit To Celsius Converter") || (converter->toString() == "Celsius To Fahrenheit Converter" ))
	{
		_decConv = nullptr;
	}

	_decConv = converter;
}

std::shared_ptr<UnitConverter> Inversion::clone()
{
	return std::make_shared<Inversion>();
}

double Inversion::convert(double input)
{
	double result;

	if(_decConv != nullptr)
	{
		result = input / _decConv->convert(1.0);
	}
	else
	{
		//if there is no decorator
		result = input;
	}

	return result;
}

std::string Inversion::toString() const
{
	std::string output =  "Inversion: Inverts the given decorator.";

	//checks whether the converter is decorated
	if(_decConv != nullptr)
	{
		output += " Given decorator: " + _decConv->toString();
	}

	return output;
}

void Inversion::print() const
{
	std::cout << toString();
}
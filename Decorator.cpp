#include "Decorator.hpp"

Decorator::Decorator()
{}

Decorator::~Decorator()
{}

double Decorator::convert(double value)
{
	return converter.convert(value);
}

std::string Decorator::toString() const
{
	return "I am just a Decorator";
}

void Decorator::print() const
{
	std::cout 	<< toString()
				<< converter.toString();
}

std::shared_ptr<UnitConverter> Decorator::clone()
{
	return std::make_shared<Decorator>();
}
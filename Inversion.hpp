#ifndef INVERSION
#define INVERSION

#include "Decorator.hpp"

class Inversion : public Decorator
{
	public:
	Inversion();
	Inversion(std::shared_ptr<UnitConverter> converter);

	double convert(double input);
	std::string toString() const;
	void print() const;

	std::shared_ptr<UnitConverter> clone();

	private:
	//decorated Converter
	std::shared_ptr<UnitConverter> _decConv;
};

#endif
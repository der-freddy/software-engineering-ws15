#ifndef YENTOEUROCONVERTER_H
#define YENTOEUROCONVERTER_H

#include "CurrencyConverter.hpp"

class YenToEuroConverter : public CurrencyConverter
{
	public:
		//Constructor
		YenToEuroConverter();
		//Constructor for chaining
		YenToEuroConverter(std::shared_ptr<UnitConverter> converter);

		double convert(double inYen);
		std::string toString() const;
		void print() const;

		std::shared_ptr<UnitConverter> clone();

	private:
		//decorated Converter
		std::shared_ptr<UnitConverter> _decConv;
};

#endif // YENTOEUROCONVERTER_H

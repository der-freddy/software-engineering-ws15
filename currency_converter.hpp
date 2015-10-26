#ifndef CURRENCY_CONVERTER
#define CURRENCY_CONVERTER

class CurrencyConverter : public Converter
{
public:
	//Constructor
	CurrencyConverter();
	~CurrencyConverter();

	double convert(double inValue) const = 0;



};

#endif // CURRENCY_CONVERTER
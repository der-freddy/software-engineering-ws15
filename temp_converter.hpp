#ifndef TEMP_CONVERTER
#define TEMP_CONVERTER

class TempConverter : public Converter
{
public:
	//Constructor
	TempConverter();
	~TempConverter();

	double convert(double inValue) const = 0;



};

#endif // TEMP_CONVERTER
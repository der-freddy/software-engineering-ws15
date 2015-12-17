#ifndef INVERSION
#define INVERSION

class Inversion : public Decorator
{
	public:
	Inversion();
	Inversion(std::shared_ptr<UnitConverter> converter);

	double convert(double inValue) override;
	std::string toString() const override;
	void print() const override;

	std::shared_ptr<UnitConverter> clone();

	private:
	//decorated Converter
	std::shared_ptr<UnitConverter> _decConv;
};

#endif
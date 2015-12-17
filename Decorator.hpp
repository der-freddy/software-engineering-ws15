#ifndef DECORATOR
#define DECORATOR

#include "UnitConverter.hpp"

class Decorator : UnitConverter
{
	public:

		Decorator();
		~Decorator();

		double convert(double value);
		std::string toString() const;
		void print() const;

		std::shared_ptr<UnitConverter> clone();

	private:

		UnitConverter converter;

};

#endif // DECORATOR

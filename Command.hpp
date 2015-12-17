#ifndef CONVERTER_COMMAND
#define CONVERTER_COMMAND

#include "UnitConverter.hpp"
#include "DollarToEuroConverter.hpp"

typedef double(UnitConverter::*Method)(double);

class Command
{
	public:
	//Constructor
	Command(std::shared_ptr<UnitConverter> converter, Method method, double input);
	
	void execute() const;

	private:
	std::shared_ptr<UnitConverter> converter_;
	Method m_method_;
	double m_param_;

};

#endif
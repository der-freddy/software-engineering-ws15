#ifndef CONVERTER_COMMAND
#define CONVERTER_COMMAND

#include "UnitConverter.hpp"
#include "DollarToEuroConverter.hpp"

typedef std::shared_ptr<UnitConverter> pointer;

typedef double(UnitConverter::*Method)(double);

class Command {

public:
	Command(pointer converter, Method method,double input ):
	converter_(converter),
	m_method_(method),
	m_param_(input)
	{}
	
	void execute() const
	{	
		std::cout << "Convert " << m_param_ << " to "
			<< (*converter_.*m_method_)(m_param_) << std::endl;
	}

private:
	pointer converter_;
	Method m_method_;
	double m_param_;

};

/*
class Command {

public:

	
	Command(DollarToEuroConverter* object, Method method, double param ):
	
	m_object_(object), m_method_(method), m_param_(param) { }
	
	void execute() const
	{	
		std::cout << "Convert " << m_param_ << " to "
			<< (m_object_->*m_method_)(m_param_) << std::endl;
	}

private:
	DollarToEuroConverter* m_object_;
	Method m_method_;
	double m_param_;

};
*/
#endif
#include "Command.hpp"

//Constructor
Command::Command(std::shared_ptr<UnitConverter> converter, Method method, double input):
converter_(converter),
m_method_(method),
m_param_(input)
{}

void Command::execute() const
{	
	std::cout 	<< "Convert " << m_param_
				<< " to " << (*converter_.*m_method_)(m_param_)
				<< std::endl;
}
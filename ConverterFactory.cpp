#include "ConverterFactory.hpp"
#include <memory>


ConverterFactory::ConverterFactory()
{}

std::shared_ptr<UnitConverter> ConverterFactory::create()
{
	std::shared_ptr<UnitConverter> converter = std::make_shared<UnitConverter>(nullptr);

	return converter;
}

std::unique_ptr<ConverterFactory> ConverterFactory::s_instance_method()
{
	//if there is no instance "behind" s_instance: create one
	if(s_instance == NULL)
	{
		s_instance = std::make_unique<ConverterFactory>();
	}

	return s_instance;
}
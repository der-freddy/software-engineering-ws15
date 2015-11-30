#ifndef CONVERTER_FACTORY
#define CONVERTER_FACTORY
#include <string>
#include <iostream>

//for std::unique_ptry
#include <memory>

#include "UnitConverter.hpp"

class ConverterFactory
{
	public:
		//std::shared_ptr<UnitConverter> create();

		//why the f*** can't i call it s_instance >:(
		static std::unique_ptr<ConverterFactory> s_instance_method();

		std::shared_ptr<UnitConverter> create();

	private:
		//Constructor
		ConverterFactory();

		//pointer to the class -> Singleton
		static std::unique_ptr<ConverterFactory> s_instance;
};

#endif // CONVERTER_FACTORY
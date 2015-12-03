#ifndef CONVERTER_FACTORY
#define CONVERTER_FACTORY
#include <iostream>

//for pointer..ish things
#include <memory>

//for create(std::string ... input)
#include <string>

//for map object_registry
#include <map>

//basic class
#include "UnitConverter.hpp"

//derived classes
#include "YenToEuroConverter.hpp"

class ConverterFactory
{
	public:
		//std::shared_ptr<UnitConverter> create();

		//why the f*** can't i call it s_instance >:(
		static std::shared_ptr<ConverterFactory> s_instance_method();

		std::shared_ptr<UnitConverter> create(std::string const& input);

		//actually needs to be private 
		ConverterFactory();

		void add_object_to_registry(std::string name, std::shared_ptr<UnitConverter> pointer);
	
	private:
		//Constructor

		//pointer to the class -> Singleton
		static std::shared_ptr<ConverterFactory> s_instance;

		//object registry
		std::map<std::string, std::shared_ptr<UnitConverter>> object_registry;
};

#endif // CONVERTER_FACTORY
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
		//why the f*** can't i call it s_instance >:(
		//static std::shared_ptr<ConverterFactory> instance();

		static ConverterFactory* instance();

		std::shared_ptr<UnitConverter> create(std::string const& input);

		bool add_object_to_registry(std::string name, std::shared_ptr<UnitConverter> pointer);

		std::string print() const;

		bool check_registry(std::string const & name) const;

	private:
		//Constructor
		ConverterFactory();
		
		//pointer to the class -> Singleton
		//static std::shared_ptr<ConverterFactory> s_instance;

		static ConverterFactory* s_instance;

		//object registry
		std::map<std::string, std::shared_ptr<UnitConverter>> object_registry;
};

#endif // CONVERTER_FACTORY
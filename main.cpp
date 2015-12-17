#include <memory>
#include <iostream>
#include <string>
#include <deque>

//factory
#include "ConverterFactory.hpp"

//basic class
#include "UnitConverter.hpp"

//derived classes
#include "DollarToEuroConverter.hpp"
#include "CelsiusToFahrenheitConverter.hpp"
#include "FahrenheitToCelsiusConverter.hpp"
#include "YenToEuroConverter.hpp"
#include "GoldToEuroConverter.hpp"
#include "Command.hpp"

#include "tinytest.h"

//secure that it's a singleton
//std::shared_ptr<ConverterFactory> ConverterFactory::s_instance = nullptr;

ConverterFactory* ConverterFactory::s_instance = nullptr;

int main(int argc, char* argv[])
{

	/*
		[0]	creating the factory
	*/

	auto factory = ConverterFactory::instance();

	/*
		[1]	register all objects | adding the prototypes
	*/

	//FahrenheitToCelsius
	factory->add_object_to_registry("FahrenheitToCelsius", std::make_shared<FahrenheitToCelsiusConverter>());
	
	//CelsiusToFahrenheit
	factory->add_object_to_registry("CelsiusToFahrenheit", std::make_shared<CelsiusToFahrenheitConverter>());
	
	//DollarToEuro
	factory->add_object_to_registry("DollarToEuro", std::make_shared<DollarToEuroConverter>());

	//GoldToEuro
	factory->add_object_to_registry("GoldToEuro", std::make_shared<GoldToEuroConverter>());

	//YenToEuro
	factory->add_object_to_registry("YenToEuro", std::make_shared<YenToEuroConverter>());


	std::deque<Command> command_list;

	std::string input;

	for (std::string line; std::getline(std::cin, input, ' ');)
	{
		std::string inputString;
		std::getline(std::cin,inputString);
		auto convert = factory->create(input);

		double (UnitConverter::*convertMethod)(double) = NULL;
		convertMethod = &UnitConverter::convert;

		command_list.push_back(
			Command{convert, convertMethod, std::stod(inputString)}
		);
	}


	for(auto&& command : command_list)
	{
		command.execute();
	}

	
	try
	{
		/*
			[2] retrieving and validating the input
		*/

		//black box testing
		if(argc == 1)
		{
			throw 3;
		}

		std::string converter_name = argv[1];
		double value = std::stod(argv[2]);

		//check whether the amount of arguments is not right
		if(argc != 3)
		{
			throw 1;
		}

		//check whether the requested converter is available
		if(!factory->check_registry(converter_name))
		{
			throw 2;
		}

		//check whether the argument is numeric
		//std::isdigit() won't work :'(

		/*
			[3] doing converter things
		*/

		auto converter = factory->create(converter_name);

		double result = converter->convert(value);

		/*
			[4] final print
		*/

		std::cout 	<< "Conversion: " 	<< converter->toString() 	<< std::endl
					<< "Value: " 		<< value 					<< std::endl 
					<< "Result: " 		<< result 					<< std::endl;

	}
	catch(int exception)
	{
		/*
			generate the usage string
		*/

		std::string case_string = "Exception: ";
		std::string usage_string = "Usage: " + std::string(argv[0]) + " <Converter> <Value>\nAvailable Converters:\n" + factory->print();

		std::string break_string = "\n------------------------------------------------------\n";

		switch(exception)
		{
			case 1:
			{
				case_string += "Wrong amount of arguments!\n";
				break;
			}

			case 2:
			{
				case_string += "The requested converter is not available!\n";
				break;
			}

			case 3:
			{
				case_string += "You need help? Take this!\n";
				break;
			}

			default:
			{

				break;
			}
		}

		/*
			Print the exception and the usage string
		*/
		std::cout << break_string << case_string << break_string << usage_string << break_string << std::endl;
	}

	return 0;
}

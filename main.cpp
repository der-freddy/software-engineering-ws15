#include <memory>
#include <iostream>
#include <string>
#include <deque>

//converter factory
#include "ConverterFactory.hpp"

//basic class
#include "UnitConverter.hpp"

//derived classes
#include "DollarToEuroConverter.hpp"
#include "CelsiusToFahrenheitConverter.hpp"
#include "FahrenheitToCelsiusConverter.hpp"
#include "YenToEuroConverter.hpp"
#include "GoldToEuroConverter.hpp"
#include "EuroToBritishPoundConverter.hpp"

//inversion decorator
#include "Inversion.hpp"

//Command pattern for Part 2
#include "Command.hpp"

//testing
#include "tinytest.h"

//exception
#include "InvalidInput.hpp"

/*
	Remaining of exercise 4
*/

//secure it is a singleton
ConverterFactory* ConverterFactory::s_instance = nullptr;

int main(int argc, char* argv[])
{
	/*
		Adding objects to registry for Part 2
		Mask:
		factory->add_object_to_registry("",std::make_shared<>(Converter));
	*/

	//initializing the factory
	auto factory = ConverterFactory::instance();

	//CelsiusToFahrenheitConverter
	factory->add_object_to_registry("CelsiusToFahrenheit", std::make_shared<CelsiusToFahrenheitConverter>());

	//FahrenheitToCelsius
	factory->add_object_to_registry("FahrenheitToCelsius", std::make_shared<FahrenheitToCelsiusConverter>());
	
	//DollarToEuro
	factory->add_object_to_registry("DollarToEuro", std::make_shared<DollarToEuroConverter>());

	//EuroToBritishPound
	factory->add_object_to_registry("EuroToBritishPound", std::make_shared<EuroToBritishPoundConverter>());
	
	//GoldToEuro
	factory->add_object_to_registry("GoldToEuro", std::make_shared<GoldToEuroConverter>());
	
	//YenToEuro
	factory->add_object_to_registry("YenToEuro", std::make_shared<YenToEuroConverter>());

	try
	{
		
		/*
			Remaining of exercise 5
			used for exception testing
		*/
		std::cout 	<< std::endl << std::endl
					<< "Part 2 Behavioural Patterns"
					<< std::endl << std::endl
					<< "Choose from these converters and type a value.\nPress ENTER after each Converter+Value.\nPress strg+d when finished."
					<< std::endl << std::endl
					<< factory->print()
					<< std::endl << std::endl
					<< "<Command> <Value>"
					<< std::endl;

		//initializing the used deque
		std::deque<Command> command_list;

		std::string input;

		//loop provided by the worksheet
		//adapted with some conversion
		for(std::string line; std::getline(std::cin, input, ' ');)
		{
			try
			{
			std::string inputString;
			std::getline(std::cin,inputString);

			//if(inputString)	//test of valid input
			//{
			//	throw InvalidInput();
			//}

			//wanted converter
			auto convert = factory->create(input);

			double(UnitConverter::*convertMethod)(double) = NULL;
			
			//reference to the method
			convertMethod = &UnitConverter::convert;

			if(convert != nullptr) //added due to exception handling
			{
				//add the reference to the deque
				command_list.push_back(Command{convert, convertMethod, std::stod(inputString)});
			}
			}
			catch(std::exception e)
			{
				std::cout << "TEST: " << e.what() << std::endl;
			}
		}

		//loop though the deque
		for(auto&& command : command_list)
		{
			command.execute();
		}
	}
	catch(int exception)
	{
		/*
			generate the usage string
		*/

		std::string case_string = "Exception: ";

		std::string usage_string = "Usage: " + std::string(argv[0]) + " <Numeric Value> \n";

		std::string break_string = "\n------------------------------------------------------\n";

		std::string explanation_string = "This is a simple program. Just type in a numeric value and you will get some conversions!\n";

		switch(exception)
		{
			case 1:
			{
				case_string += "You need help? Take this!\n";
				break;
			}

			case 2:
			{
				case_string += "Wrong amount of arguments!\n";
				break;
			}

			default:
			{
				case_string += "Unknown Exception. So sorry!\n";
				break;
			}
		}

		std::cout << break_string << case_string << usage_string << break_string << explanation_string << std::endl;
	}

	
	return 0;
}
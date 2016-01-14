//test
#include "catch.hpp"

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

/*
	Remaining of exercise 4
*/

//secure it is a singleton
ConverterFactory* ConverterFactory::s_instance = nullptr;


TEST_CASE("Converter Test")
{	
	std::vector <unsigned int> v0 (50); /*Creates vector with space for
	100 Integers*/
	
	for ( std::vector <unsigned int >::iterator i = v0.begin(); i != v0.end();++i)
	{
	  * i = std::rand() % 51;
	}

	std::vector<unsigned int>::iterator newEnd = std::remove_if (v0.begin(), v0.end(), isOdd);

	v0.erase(newEnd, v0.end());

	//std::copy(std::begin(v0),std::end(v0), std::ostream_iterator<unsigned int>(std::cout,"\n"));

	if(std::all_of(v0.begin(), v0.end(), isEven))
	std::cout << "All even" << std::endl;
	
	REQUIRE(std::all_of(v0.begin(),v0.end(),isEven));
	
	
}

int main(int argc, char* argv[])
{
	/*
		Adding objects to registry for Part 2
		Mask:
		//
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
			Part 1.1 Structural Patterns
		*/
		std::cout 	<< std::endl << std::endl
					<< "Part 1.1 Structural Patterns";
		
		/*
			Testing converter chaining
		*/
		std::cout 	<< std::endl << std::endl
					<< "Converter chaining"
					<< std::endl << std::endl;

		//Converting from Yen to Euro to Britsh Pound
		auto converter_1 = std::make_shared<EuroToBritishPoundConverter>(std::make_shared<YenToEuroConverter>());

		double value_1 = 5000.0;

		double result_1 = converter_1->convert(value_1);

		std::cout 	<< "Converting from Yen to Euro to Britsh Pound"
					<< std::endl
					<< "Value: " << value_1
					<< std::endl
					<< converter_1->toString()
					<< std::endl
					<< "Result: " << result_1
					<< std::endl;

		/*
			Testing the inversion Decorator
		*/

		std::cout 	<< std::endl << std::endl
					<< "Inversion Decorator"
					<< std::endl << std::endl;

		//Converting from Euro to British Pound
		auto converter_2 = std::make_shared<EuroToBritishPoundConverter>();

		double value_2 = 42.0;

		double result_2 = converter_2->convert(value_2);

		std::cout 	<< "Converting from Euro to British Pound"
					<< std::endl
					<< "Value: " << value_2
					<< std::endl
					<< converter_2->toString()
					<< std::endl
					<< "Result: " << result_2
					<< std::endl;

		//Converting from British Pound to Euro via Inversion
		auto converter_3 = std::make_shared<Inversion>(std::make_shared<EuroToBritishPoundConverter>());

		double value_3 = result_2;

		double result_3 = converter_3->convert(value_3);

		std::cout 	<< "Converting from British Pound to Euro via Inversion"
					<< std::endl
					<< "Value: " << value_3
					<< std::endl
					<< converter_3->toString()
					<< std::endl
					<< "Result: " << result_3
					<< std::endl;

		/*
			Part 2 Behavioural Patterns
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
			std::string inputString;
			std::getline(std::cin,inputString);

			//wanted converter
			auto convert = factory->create(input);

			double(UnitConverter::*convertMethod)(double) = NULL;
			
			//reference to the method
			convertMethod = &UnitConverter::convert;

			//add the reference to the deque
			command_list.push_back(Command{convert, convertMethod, std::stod(inputString)});
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

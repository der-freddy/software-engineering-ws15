#include <memory>
#include <iostream>
#include <string>

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
#include "tinytest.h"

/*
	Remaining of exercise 4
*/

//secure it is a singleton
ConverterFactory* ConverterFactory::s_instance = nullptr;

int main(int argc, char* argv[])
{
	try
	{
		/*
			[0] retrieving and validating the input
		*/

		//black box testing
		if(argc == 1)
		{
			throw 1;
		}

		//check whether the amount of arguments is not right
		if(argc != 2)
		{
			throw 2;
		}

		double value = std::stod(argv[1]);

		/*
			[1] doing converter things
		*/
		
		//Celsius to Fahrenheit to Celsius | i know it is nonsense, but it is just for testing
		auto converter = std::make_shared<CelsiusToFahrenheitConverter>(std::make_shared<FahrenheitToCelsiusConverter>());

		double result = converter->convert(value);
		
		/*
			[2] final print
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

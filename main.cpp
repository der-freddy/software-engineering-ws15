#include <memory>
#include <iostream>
#include <string>

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
#include "tinytest.h"

//secure that it's a singleton
std::shared_ptr<ConverterFactory> ConverterFactory::s_instance = nullptr;

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

	try
	{
		/*
			[2] retrieving and validating the input
		*/

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

	/*
		Test Section:
	*/
	/*
	std::cout << "TEST SECTION: ";

	double test_value = 50.0;

	std::cout << "Value: " << test_value << std::endl;
	
	//FahrenheitToCelsius
	std::string test_name1 = "FahrenheitToCelsius";
	
	auto converter1 = factory->create(test_name1);

	std::cout 	<< converter1->toString()
				<< ": "<< converter1->convert(test_value) << std::endl;

	//CelsiusToFahrenheit
	std::string test_name2 = "CelsiusToFahrenheit";

	auto converter2 = factory->create(test_name2);

	std::cout 	<< converter2->toString()
				<< ": "<< converter2->convert(test_value) << std::endl;

	*/

	/*
 	std::string arg1 = argv[1];
	double arg2 = std::stod(argv[2]);


	if(arg1 == "DollarToEuro")
	{
	// Dollar to Euro Converter
	auto myConverter = std::make_shared<DollarToEuroConverter>();
	double aLotOfEuros = myConverter->convert(arg2);
	std::cout << myConverter->toString() << " has converted "<< arg2 << " Dollar to " << aLotOfEuros <<" Euros!\n"<<std::endl;
	}

	else if(arg1 == "YenToEuro")
	{
	// Yen to Euro Converter
	auto yentoeuro = std::make_shared<YenToEuroConverter>();
	double aLotOfEuros = yentoeuro->convert(arg2);
	std::cout << yentoeuro->toString() << " has converted "<< arg2 << " Yen to " << aLotOfEuros <<" Euros!\n"<<std::endl;
	}

	else if(arg1 == "GoldToEuro")
	{
	//Gold to Euro
	auto goldtoeuro = std::make_shared<GoldToEuroConverter>();
	double euro = goldtoeuro->convert(arg2);
	std::cout << goldtoeuro->toString() << " has converted " << arg2 << "oz to " << euro << " Euros!\n"<<std::endl;
	}

	else if(arg1 == "FahrenheitToCelsius")
	{
	//Fahrenheit to Celsius Converter
	auto ftoc = std::make_shared<FahrenheitToCelsiusConverter>();
	double celsius = ftoc->convert(arg2);
	std::cout << ftoc->toString() << " has converted "<< arg2 << " Fahrenheit to " << celsius <<" Celsius!\n"<<std::endl;  
	}

	else if(arg1 == "CelsiusToFahrenheit")
	{
	//Celsius to Fahrenheit Converter
	auto ctof = std::make_shared<CelsiusToFahrenheitConverter>();
	double fahrenheit = ctof->convert(arg2);
	std::cout << ctof->toString() << " has converted "<< arg2 << " Celsius to " << fahrenheit <<" Fahrenheit!\n"<<std::endl;    
	}
	
	else
	{
	std::cout << "ERROR" <<std::endl;
	}

	*/
	return 0;
}

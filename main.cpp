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



std::shared_ptr<ConverterFactory> ConverterFactory::s_instance = nullptr;


int main(int argc, char* argv[])
{
	//creating the factory
	auto factory = ConverterFactory::s_instance_method();

	std::string name = "FahrenheitToCelsius";

	auto FaToCeConv_ptr = std::make_shared<FahrenheitToCelsiusConverter>();

	factory->add_object_to_registry(name, FaToCeConv_ptr);

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

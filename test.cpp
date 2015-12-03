#include "tinytest.h"

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

ConverterFactory* ConverterFactory::s_instance = nullptr;

int test_DollarToEuro()
{
	std::string converter_string = "DollarToEuro";
//creating the factory
	auto factory = ConverterFactory::instance();

//registering converters
	
	factory->add_object_to_registry(converter_string, std::make_shared<DollarToEuroConverter>());

	auto converter = factory->create(converter_string);

	TINYTEST_EQUAL_EPSILON(converter->convert(0.0), 0.0);
	TINYTEST_EQUAL_EPSILON(converter->convert(11.363636), 10.0);
	TINYTEST_EQUAL_EPSILON(converter->convert(22.9318181), 20.18);

	return 1;  // Always return a value different than 0 at test end.
}

int test_CelsiusToFahrenheit()
{
	std::string converter_string = "CelsiusToFahrenheit";
//creating the factory
	auto factory = ConverterFactory::instance();

//registering converters
	
	factory->add_object_to_registry(converter_string, std::make_shared<CelsiusToFahrenheitConverter>());

	auto converter = factory->create(converter_string);

	TINYTEST_EQUAL_EPSILON(converter->convert(0.0), 32.0);
	TINYTEST_EQUAL_EPSILON(converter->convert(32.0), 89.6);
	TINYTEST_EQUAL_EPSILON(converter->convert(-10), 14.0);

	return 1;  // Always return a value different than 0 at test end.
}

int test_FahrenheitToCelsius()
{
	std::string converter_string = "FahrenheitToCelsius";
//creating the factory
	auto factory = ConverterFactory::instance();

//registering converters
	
	factory->add_object_to_registry(converter_string, std::make_shared<CelsiusToFahrenheitConverter>());

	auto converter = factory->create(converter_string);

	TINYTEST_EQUAL_EPSILON(converter->convert(32.0), 0.0);
	TINYTEST_EQUAL_EPSILON(converter->convert(89.6), 32.0);
	TINYTEST_EQUAL_EPSILON(converter->convert(14.0), -10);

	return 1;  // Always return a value different than 0 at test end.
}

/*
	GoldToEuro has been skipped because of finanical crisis (or vague values)
*/

int test_YenToEuro()
{
	std::string converter_string = "YenToEuro";
//creating the factory
	auto factory = ConverterFactory::instance();

//registering converters
	
	factory->add_object_to_registry(converter_string, std::make_shared<CelsiusToFahrenheitConverter>());

	auto converter = factory->create(converter_string);

	TINYTEST_EQUAL_EPSILON(converter->convert(32.0), 0.0);
	TINYTEST_EQUAL_EPSILON(converter->convert(89.6), 32.0);
	TINYTEST_EQUAL_EPSILON(converter->convert(14.0), -10);

	return 1;  // Always return a value different than 0 at test end.
}

TINYTEST_START_SUITE(ConverterSuite);

// Currency Tests
TINYTEST_ADD_TEST(test_DollarToEuro);
//TINYTEST_ADD_TEST(testEuroToDollar);
//TINYTEST_ADD_TEST(testEuroToDanishKrone);
//TINYTEST_ADD_TEST(testCentsToInches);
//TINYTEST_ADD_TEST(testKilometersToMiles);

TINYTEST_END_SUITE();

TINYTEST_MAIN_SINGLE_SUITE(ConverterSuite);
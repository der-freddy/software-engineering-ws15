#include "tinytest.h"
#include "../DollarToEuroConverter.hpp"
#include "../YenToEuroConverter.hpp"
#include "../GoldToEuroConverter.hpp"
#include "../FahrenheitToCelsiusConverter.hpp"
#include "../CelsiusToFahrenheitConverter.hpp"
#include <memory>

int testDollarToEuroConverter()
{
  	auto myConverter = std::make_shared<DollarToEuroConverter>();

	TINYTEST_EQUAL_EPSILON(0.0, myConverter->convert(0.0));
	TINYTEST_EQUAL_EPSILON(8800.0, myConverter->convert(10000.0));
	TINYTEST_EQUAL_EPSILON(7744.0, myConverter->convert(8800.0));

	return 1;
}

int testYenToEuroConverter()
{
	auto yentoeuro = std::make_shared<YenToEuroConverter>();

	TINYTEST_EQUAL_EPSILON(0.0, yentoeuro->convert(0.0));
	TINYTEST_EQUAL_EPSILON(45.102, yentoeuro->convert(6000));
	TINYTEST_EQUAL_EPSILON(3.7585, yentoeuro->convert(500))

	return 1;
}

int testGoldToEuroConverter()
{
	auto goldtoeuro = std::make_shared<GoldToEuroConverter>();

	TINYTEST_EQUAL_EPSILON(0.0, goldtoeuro->convert(0.0));
	TINYTEST_EQUAL_EPSILON(1067.4, goldtoeuro->convert(1.0));
	TINYTEST_EQUAL_EPSILON(469656.0, goldtoeuro->convert(440.0));


	return 1;
}

int testFahrenheitToCelsiusConverter()
{
	auto ftoc = std::make_shared<FahrenheitToCelsiusConverter>();

	TINYTEST_EQUAL_EPSILON(0.0, ftoc->convert(32.0));
	TINYTEST_EQUAL_EPSILON(26.6, ftoc->convert(80.0));
	TINYTEST_EQUAL_EPSILON(12.7, ftoc->convert(55.0));


	return 1;
}

int testCelsiusToFahrenheitConverter()
{
	auto ctof = std::make_shared<CelsiusToFahrenheitConverter>();

	TINYTEST_EQUAL_EPSILON(32.0, ctof->convert(0.0));
	TINYTEST_EQUAL_EPSILON(96.8, ctof->convert(36.0));
	TINYTEST_EQUAL_EPSILON(107.6, ctof->convert(42.0));

	return 1;
}


TINYTEST_START_SUITE(ConverterSuite);

// Currency Tests
TINYTEST_ADD_TEST(testDollarToEuroConverter);
TINYTEST_ADD_TEST(testYenToEuroConverter);
TINYTEST_ADD_TEST(testGoldToEuroConverter);
TINYTEST_ADD_TEST(testFahrenheitToCelsiusConverter);
TINYTEST_ADD_TEST(testCelsiusToFahrenheitConverter);



TINYTEST_END_SUITE();

TINYTEST_MAIN_SINGLE_SUITE(ConverterSuite);
cmake_minimum_required(VERSION 2.8)
project (Software_Eng)
set (CMAKE_CXX_FLAGS "-std=gnu++11" )


add_executable(converter main.cpp
						CelsiusToFahrenheitConverter.cpp
						FahrenheitToCelsiusConverter.cpp
						DollarToEuroConverter.cpp
						YenToEuroConverter.cpp
						UnitConverter.cpp
						TempConverter.cpp
						CurrencyConverter.cpp
						GoldToEuroConverter.cpp
						ConverterFactory.cpp
						EuroToBritishPoundConverter.cpp
						Decorator.cpp
						Inversion.cpp
						Command.cpp)

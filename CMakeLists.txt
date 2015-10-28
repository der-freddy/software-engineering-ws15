cmake_minimum_required(VERSION 2.8)
project (Software_Eng)
set (CMAKE_CXX_FLAGS "-std=gnu++11" )


add_executable( test main.cpp CelsiusToFahrenheitConverter.cpp FahrenheitToCelsiusConverter.cpp dollartoeuroconverter.cpp YenToEuroConverter.cpp converter.cpp TempConverter.cpp CurrencyConverter.cpp GoldToEuroConverter.cpp)
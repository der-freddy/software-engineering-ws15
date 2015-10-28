cmake_minimum_required(VERSION 2.8)
project (Software_Eng)

add_executable( CtoF CelsiusToFahrenheitConverter.cpp converter.cpp temp_converter.cpp)
add_executable( FtoC FahrenheitToCelsiusConverter.cpp converter.cpp temp_converter.cpp)
add_executable( DtoE dollartoeuroconverter.cpp converter.cpp currency_converter.cpp)
add_executable( EtoD YenToEuroConverter.cpp converter.cpp currency_converter.cpp)

#include <memory>
#include <iostream>
#include "dollartoeuroconverter.hpp"
#include "CelsiusToFahrenheitConverter.hpp"
#include "FahrenheitToCelsiusConverter.hpp"
#include "YenToEuroConverter.hpp"


int main(int argc, char* argv[])
{
  //std::string conversion = argv[0];
  //std::string value = argv[1];

  /*
   * TODO
   *
   * use desired conversion here
   *
  */

   // Dollar to Euro Converter
  auto myConverter = std::make_shared<dollarToEuroConverter>();
  double aLotOfDollars = 10000;
  double aLotOfEuros = myConverter->convert(aLotOfDollars);
  std::cout << myConverter->toString() << " has converted "<< aLotOfDollars << " Dollar to " << aLotOfEuros <<" Euros!\n"<<std::endl;
  
  // Yen to Euro Converter

  auto yentoeuro = std::make_shared<YenToEuroConverter>();
  double aLotOfYen = 10000;
  aLotOfEuros = yentoeuro->convert(aLotOfYen);
  std::cout << yentoeuro->toString() << " has converted "<< aLotOfYen << " Yen to " << aLotOfEuros <<" Euros!\n"<<std::endl;

  auto ftoc = std::make_shared<FahrenheitToCelsiusConverter>();
  double fahrenheit = 32;
  double celsius = ftoc->convert(fahrenheit);
  std::cout << ftoc->toString() << " has converted "<< fahrenheit << " Fahrenheit to " << celsius <<" Celsius!\n"<<std::endl;  

  auto ctof = std::make_shared<CelsiusToFahrenheitConverter>();
  celsius = 100;
  fahrenheit = ctof->convert(celsius);
  std::cout << ctof->toString() << " has converted "<< fahrenheit << " Celsius to " << celsius <<" Fahrenheit!\n"<<std::endl;    

  return 0;
}


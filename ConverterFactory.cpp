#include "ConverterFactory.hpp"
#include <memory>


ConverterFactory::ConverterFactory()
{}

std::shared_ptr<UnitConverter> ConverterFactory::create(std::string const& input)
{

	auto it = mymap.find('b');
  	if(it != mymap.end())
    	mymap.erase (it);
	
	/*
	for(auto const & element : object_registry)
	{

	}
	*/

	return std::make_shared<YenToEuroConverter>();
}

//unique_ptr would fit better
std::shared_ptr<ConverterFactory> ConverterFactory::s_instance_method()
{
	//if there is no instance "behind" s_instance: create one
	if(!s_instance)
	{
		s_instance = std::make_shared<ConverterFactory>();
	}

	return s_instance;
}

void ConverterFactory::add_object_to_registry(std::string name, std::shared_ptr<UnitConverter> pointer)
{
	/*
		there needs to be some checking, whether the name is already used
	*/
	object_registry.insert(std::pair<std::string, std::shared_ptr<UnitConverter>>(name,pointer));
}

/*

std::shared_ptr<Shape> SDFLoader::createBox(std::istringstream& textStream)
{
	std::string name,materialName;
	float x0,y0,z0,x1,y1,z1;
	textStream >> name >> x0 >> y0 >> z0 >> x1 >> y1 >> z1 >> materialName;
	//std::cout << name << x0 << y0 << z0 << x1 << y1 << z1 << materialName;
	return std::make_shared<Box>(glm::vec3(x0,y0,z0),glm::vec3(x1,y1,z1),name,_materials.find(materialName)->second);
}
*/

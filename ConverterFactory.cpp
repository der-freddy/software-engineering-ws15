#include "ConverterFactory.hpp"
#include <memory>


ConverterFactory::ConverterFactory()
{}

std::shared_ptr<UnitConverter> ConverterFactory::create()
{
	return std::make_shared<UnitConverter>(nullptr);
}

static std::unique_ptr<ConverterFactory> ConverterFactory::s_instance_method()
{
	//if there is no instance "behind" s_instance: create one
	if(s_instance == NULL)
	{
		s_instance = std::make_unique<ConverterFactory>();
	}

	return s_instance;
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

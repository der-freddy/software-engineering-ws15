#include "ConverterFactory.hpp"

ConverterFactory::ConverterFactory()
{}

/*
	returns the only instance of ConverterFactory: Singleton
*/

ConverterFactory* ConverterFactory::instance()
{
	//if there is no instance "behind" s_instance: create one
	if(!s_instance)
	{
		s_instance = new ConverterFactory;
	}
	return s_instance;
}

/*
	What a pity! It does not work with shared_ptr :(
*/

/*
std::shared_ptr<ConverterFactory> ConverterFactory::instance()
{
	//if there is no instance "behind" s_instance: create one
	if(!s_instance)
	{
		s_instance = std::make_shared<ConverterFactory>();
	}

	return s_instance;
}
*/
/*
	adds an UnitConverter Object to the object_registry map
	returns true if successfull
	returns false if the object is already registered
*/
bool ConverterFactory::add_object_to_registry(std::string name, std::shared_ptr<UnitConverter> pointer)
{
	//checks whether the object is already registered
	if(check_registry(name))
	{
		return false;
	}
	else
	{
		//registers the object if there was no equivalent found
		object_registry.insert(std::pair<std::string, std::shared_ptr<UnitConverter>>(name,pointer));
		return true;
	}
}

/*
	checks whether the name is already in the registry
	returns true if it is already registered
	returns false if there is no entry
*/
bool ConverterFactory::check_registry(std::string const & name) const
{
	//checks whether the object is registered
	for(auto const & element : object_registry)
	{
		if(element.first == name)
		{
			return true;
		}
	}
	return false;
}

/*
	returns an UnitConverter object determined by the given name string
*/
std::shared_ptr<UnitConverter> ConverterFactory::create(std::string const& name)
{
	/*
	auto it = object_registry.find(name);
	if(it != object_registry.end())
	{
		return it->second->clone();
	}
	*/

	for(auto const & element : object_registry)
	{
		if(element.first == name)
		{
			return element.second->clone();
		}
	}

	/*
	another try without .find()
	for(auto const & element : object_registry)
	{

	}
	*/
}

std::string ConverterFactory::print() const
{
	std::string converters;
	for(auto const & element : object_registry)
	{
		//std::cout << "first: " << element.first << " second: " << element.second->toString() << std::endl;
		converters += "first: " + element.first + "| second: " + element.second->toString() + "\n";
	}
	return converters;
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

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
	EDIT:
	throws an exception if ther is no entry
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
	try
	{
		//loops through the registry
		for(auto const & element : object_registry)
		{
			if(element.first == name)
			{
				return element.second->clone();
			}
		}
		throw ConverterNotFound();
	}
	catch(ConverterNotFound exception) //doesn't work with std::exception exception because it always prints std::exception and not the .what() of the derived classes
	{
		std::cout << exception.what() << std::endl;
		return nullptr;	//neccessary
	}
}

std::string ConverterFactory::print() const
{
	std::string converters;
	for(auto const & element : object_registry)
	{
		converters += "Command: " + element.first + "\nConverter: " + element.second->toString() + "\n\n";
	}
	return converters;
}

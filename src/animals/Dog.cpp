#include <nupic/animals/Dog.hpp>

using namespace nupic::animals;

Dog::Dog(std::string& name)
	: name_(name)
{
}

void Dog::setName(std::string& value)
{
	name_ = value;
}

std::string& Dog::getName()
{
	return name_;
}

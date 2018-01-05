#include <nupic/animals/Cat.hpp>

using namespace nupic::animals;

Cat::Cat(std::string& name)
	: name_(name)
{
}

void Cat::setName(std::string& value)
{
	name_ = value;
}

std::string& Cat::getName()
{
	return name_;
}

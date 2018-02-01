#include "nupic/animals/Cat.hpp"

#include <utility>

using namespace nupic::animals;
using namespace std;

Cat::Cat(string name)
	: name_(move(name))
{
}

void Cat::setName(const string& name)
{
	name_ = name;
}

const string& Cat::getName() const
{
	return name_;
}

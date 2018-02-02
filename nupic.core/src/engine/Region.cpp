#include "nupic/engine/Region.hpp"

using namespace nupic::engine;

struct Region::Impl
{

};

Region::Region() :
	impl_(make_unique<Impl>())
{
}

Region::~Region() = default;
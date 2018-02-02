#include "nupic/engine/LinkPolicy.hpp"

using namespace nupic::engine;

struct LinkPolicy::Impl
{

};

LinkPolicy::LinkPolicy() :
	impl_(make_unique<Impl>())
{
}

LinkPolicy::~LinkPolicy() = default;
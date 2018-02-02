#include "nupic/engine/Network.hpp"

using namespace nupic::engine;

struct Network::Impl
{

};

Network::Network() :
	impl_(make_unique<Impl>())
{
}

Network::~Network() = default;
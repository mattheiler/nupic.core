#include "nupic/engine/Output.hpp"

using namespace nupic::engine;

struct Output::Impl
{
	Region* region;

	explicit Impl(Region* region) :
		region(region)
	{
	}
};

Output::Output(Region* region) :
	impl_(make_unique<Impl>(region))
{
}

Output::~Output() = default;

Region* Output::getRegion() const
{
	return impl_->region;
}

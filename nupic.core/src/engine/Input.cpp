#include "nupic/engine/Input.hpp"

using namespace nupic::engine;

struct Input::Impl
{
	Region* region;

	explicit Impl(Region* region) :
		region(region)
	{
	}
};

Input::Input(Region* region) :
	impl_(make_unique<Impl>(region))
{
}

Input::~Input() = default;

Region* Input::getRegion() const
{
	return impl_->region;
}

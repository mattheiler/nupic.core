#include "nupic/engine/Link.hpp"

using namespace nupic::engine;

struct Link::Impl
{
	string type;

	string params;

	string sourceRegionName;

	string sourceOutputName;

	string targetRegionName;

	string targetInputName;

	size_t propagationDelay;

	Impl(string type,
	     string params,
	     string sourceRegionName,
	     string sourceOutputName,
	     string targetRegionName,
	     string targetInputName,
	     const size_t propagationDelay) :
		type(move(type)),
		params(move(params)),
		sourceRegionName(move(sourceRegionName)),
		sourceOutputName(move(sourceOutputName)),
		targetRegionName(move(targetRegionName)),
		targetInputName(move(targetInputName)),
		propagationDelay(propagationDelay)
	{
	}
};


Link::Link(string type,
           string params,
           string sourceRegionName,
           string sourceOutputName,
           string targetRegionName,
           string targetInputName,
           size_t propagationDelay) :
	impl_(make_unique<Impl>(move(type),
	                        move(params),
	                        move(sourceRegionName),
	                        move(sourceOutputName),
	                        move(targetRegionName),
	                        move(targetInputName),
	                        propagationDelay))
{
}

Link::~Link() = default;

string& Link::getType() const
{
	return impl_->type;
}

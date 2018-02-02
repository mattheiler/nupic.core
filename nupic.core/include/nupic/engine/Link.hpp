#pragma once

#include <memory>
#include <string>

using namespace std;

namespace nupic
{
	namespace engine
	{
		class Link
		{
		public:

			Link(string type,
			     string params,
			     string sourceRegionName,
			     string sourceOutputName,
			     string targetRegionName,
			     string targetInputName,
			     size_t propagationDelay = 0);

			~Link();

			string& getType() const;

			// TODO other members

		private:

			struct Impl;

			unique_ptr<Impl> impl_;
		};
	}
}

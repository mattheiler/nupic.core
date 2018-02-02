#pragma once

#include "Region.hpp"

#include <memory>

using namespace std;

namespace nupic
{
	namespace engine
	{
		class Output
		{
		public:

			explicit Output(Region* region);

			~Output();

			Region* getRegion() const;

		private:

			struct Impl;

			unique_ptr<Impl> impl_;
		};
	};
}

#pragma once

#include "Region.hpp"

#include <memory>

using namespace std;

namespace nupic
{
	namespace engine
	{
		class Input
		{
		public:

			explicit Input(Region* region);

			~Input();

			Region* getRegion() const;

		private:

			struct Impl;

			unique_ptr<Impl> impl_;
		};
	}
}

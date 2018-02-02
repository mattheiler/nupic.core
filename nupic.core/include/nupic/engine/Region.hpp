#pragma once

#include <memory>

using namespace std;

namespace nupic
{
	namespace engine
	{
		class Region
		{
		public:

			Region();

			~Region();

		private:

			struct Impl;

			unique_ptr<Impl> impl_;
		};
	}
}

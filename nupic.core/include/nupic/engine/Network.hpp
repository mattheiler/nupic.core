#pragma once

#include <memory>

using namespace std;

namespace nupic
{
	namespace engine
	{
		class Network
		{
		public:

			Network();

			~Network();

		private:

			struct Impl;

			unique_ptr<Impl> impl_;
		};
	}
}


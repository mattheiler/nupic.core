#pragma once

#include <memory>

using namespace std;

namespace nupic
{
	namespace engine
	{
		class LinkPolicy
		{
		public:

			LinkPolicy();

			~LinkPolicy();

		private:

			struct Impl;

			unique_ptr<Impl> impl_;
		};
	}
}


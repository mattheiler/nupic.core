#include "nupic/engine/Input.hpp"
#include "nupic/engine/Region.hpp"

#include "Region.cpp"

using namespace System;

using namespace std;

namespace Nupic {

	namespace Engine {

		public ref class Input
		{
		private:

			nupic::engine::Input* input_;

			Region^ region_;

		public:

			Input(Region^ region)
			{
				input_ = new nupic::engine::Input((nupic::engine::Region*) region->region_);
				region_ = region;
			}

			~Input() { this->!Input(); }

			!Input() { delete input_; }

			property Region^ Region {

				Nupic::Engine::Region^ get() { return region_; }

			}
		};

	}
}

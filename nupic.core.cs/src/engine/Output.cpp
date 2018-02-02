#include "nupic/engine/Output.hpp"
#include "nupic/engine/Region.hpp"

#include "Region.cpp"

using namespace System;

using namespace std;

namespace Nupic {

	namespace Engine {

		public ref class Output
		{
		private:

			nupic::engine::Output* output_;

			Region^ region_;

		public:

			Output(Region^ region)
			{
				output_ = new nupic::engine::Output((nupic::engine::Region*) region->region_);
				region_ = region;
			}

			~Output() { this->!Output(); }

			!Output() { delete output_; }

			property Region^ Region {

				Nupic::Engine::Region^ get() { return region_; }

			}
		};

	}
}

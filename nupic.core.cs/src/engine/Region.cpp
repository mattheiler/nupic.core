#include "nupic/engine/Region.hpp"

#include <stdexcept>

namespace Nupic {

	namespace Engine {

		public ref class Region
		{
		internal:

			const nupic::engine::Region* region_;

			Region(nupic::engine::Region* region) { region_ = region; }

		public:

			Region() { region_ = new nupic::engine::Region(); }

			~Region() { this->!Region(); }

			!Region() { delete region_; }

		};

	}
}

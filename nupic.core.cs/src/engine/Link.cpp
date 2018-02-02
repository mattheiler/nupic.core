#include "nupic/engine/Link.hpp"

#include <msclr/marshal_cppstd.h>

using namespace msclr::interop;
using namespace std;

using namespace System;

namespace Nupic {

	namespace Engine {

		public ref class Link
		{
		private:

			nupic::engine::Link* link_;

		public:

			Link(String^ type,
				 String^ params,
				 String^ sourceRegionName,
				 String^ sourceOutputName,
				 String^ targetRegionName,
				 String^ targetInputName)
			{
				link_ = new nupic::engine::Link(marshal_as<string>(type),
												marshal_as<string>(params),
												marshal_as<string>(sourceRegionName),
												marshal_as<string>(sourceOutputName),
												marshal_as<string>(targetRegionName),
												marshal_as<string>(targetInputName),
												1);
			}

			~Link() { this->!Link(); }

			!Link() { delete link_; }

			property String^ Type {

				String^ get() { return marshal_as<String^>(link_->getType()); }

			}
		};

	}
}

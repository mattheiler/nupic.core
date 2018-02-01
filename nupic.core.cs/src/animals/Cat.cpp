#include "nupic/animals/Cat.hpp"

#include <msclr/marshal_cppstd.h>

using namespace msclr::interop;
using namespace std;

using _Cat = nupic::animals::Cat;

using namespace System;

namespace Workshop {

	namespace Animals {

		public ref class Cat
		{
		private:

			_Cat * cat_;

		public:

			Cat(String^ name) { cat_ = new _Cat(marshal_as<string>(name)); }

			~Cat() { this->!Cat(); }

			!Cat() { delete cat_; }

			property String^ Name {

				String^ get() { return marshal_as<String^>(cat_->getName()); }

				void set(String^ value) { cat_->setName(marshal_as<string>(value)); }

			}
		};

	}
}



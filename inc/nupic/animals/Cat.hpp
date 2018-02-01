#ifndef CAT
#define CAT

#include <string>

namespace nupic
{
	namespace animals
	{
		class Cat
		{
		private:
			std::string name_;

		public:

			explicit Cat(std::string& name);

			void setName(std::string& name);

			std::string& getName();
		};
	}
}

#endif

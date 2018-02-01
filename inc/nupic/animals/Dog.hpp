#ifndef CAT
#define CAT

#include <string>

namespace nupic
{
	namespace animals
	{
		class Dog
		{
		private:
			std::string name_;

		public:

			explicit Dog(std::string& name);

			void setName(std::string& name);

			std::string& getName();
		};
	}
}

#endif
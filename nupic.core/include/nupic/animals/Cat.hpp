#ifndef CAT
#define CAT

#include <string>

using namespace std;

namespace nupic
{
	namespace animals
	{
		class Cat
		{
			string name_;

		public:

			explicit Cat(string name);

			const string& getName() const;

			void setName(const string& name);
		};
	}
}

#endif

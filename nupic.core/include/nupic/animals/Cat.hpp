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
		public:

			explicit Cat(string name);

			const string& getName() const;

			void setName(const string& name);

		private:
			string name_;
		};
	}
}

#endif

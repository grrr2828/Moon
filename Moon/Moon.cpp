#include <vector>

#include "AppI.h"

namespace moon {


	class Test : public AppI
	{
	public:


		Test(const char* name)
			: AppI(name)
		{
			
		}

		bool update() override
		{

			return true;
		}

	};
}



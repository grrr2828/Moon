#include <vector>

#include "AppI.h"

namespace moon {


	class Test : public AppI
	{
	public:


		Test()
			: AppI()
		{
			
		}

		bool Update() override
		{

			return true;
		}

	};
}



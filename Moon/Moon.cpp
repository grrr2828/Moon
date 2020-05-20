#include <vector>

#include "AppI.h"
#include "Device.h"

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
			return AppI::Update();
		}

	};
}

int main(int argc, const char* const* argv)
{
	auto context = moon::s_ctx;
	context.AddApp( new moon::Test() );

	return context.run(argc, argv);
}

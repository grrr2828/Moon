#include "platform.h"

#if DEVICE_USE_WINDOWS

namespace moon {

	struct Context
	{
		Context() {};

		int run(int argc, const char* const* argv)
		{
			return 0;
		}
	};



	static Context s_ctx;

}

int main(int argc, const char* const* argv)
{
	return moon::s_ctx.run(argc, argv);
}

#endif // DEVICE_USE_WINDOWS
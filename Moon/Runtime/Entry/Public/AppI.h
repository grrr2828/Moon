#pragma once

namespace moon {
	
	class AppI
	{
	public:
		AppI(const char* name);

		virtual ~AppI() = 0;

		virtual bool update();

		int runApp();

	};
}
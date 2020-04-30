#include "AppI.h"

namespace moon {

	AppI::AppI(const char* name)
	{
		
	}

	AppI::~AppI()
	{

	}

	bool AppI::update()
	{
		return false;
	}

	int AppI::runApp()
	{
		while (this->update())
		{
			
		}

		return 0;
	}

}
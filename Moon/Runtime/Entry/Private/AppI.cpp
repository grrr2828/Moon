#include "AppI.h"
#include "Context.h"
#include "RendererGL.h"

namespace moon {

	AppI::AppI()
	{
		rendererProcessor = new RendererProcessor();
	}

	AppI::~AppI()
	{
		delete rendererProcessor;
		rendererProcessor = nullptr;
	}

	bool AppI::Update()
	{
		return false;
	}

	void AppI::RenderFrame()
	{
		rendererProcessor->Run();
	}

}
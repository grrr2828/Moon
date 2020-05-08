#pragma once

#include "RendererPipeline.h"
#include "RendererContextI.h"
#include "Camera.h"


namespace moon {

	class RendererProcessor
	{
	public:
		RendererProcessor();
		~RendererProcessor();

		void Run();

		RendererContextI* r_ctx;

	private:

		std::vector<Camera*> cameras;
		RendererPipeline* currentPipeline;
	};
}
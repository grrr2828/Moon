#pragma once

#include "RendererPipeline.h"
#include "RendererContextI.h"

namespace moon {

	class RendererProcessor
	{
	public:
		RendererProcessor();
		~RendererProcessor();

		void AddPipeline(RendererPipeline* pipeline);

		void Run();

		RendererContextI* r_ctx;
	private:
		
		std::vector<RendererPipeline*> _pipelineList;
	};
}
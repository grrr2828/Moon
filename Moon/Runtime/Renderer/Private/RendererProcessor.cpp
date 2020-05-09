#include "RendererProcessor.h"
#include "RendererGL.h"
#include "CullResults.h"

namespace moon {

	RendererProcessor::RendererProcessor()
	{
		r_ctx = new RendererContextGL();
		r_ctx->Init();



		currentPipeline = new RendererPipeline();

				
	}

	RendererProcessor::~RendererProcessor()
	{
		if (r_ctx) {
			delete r_ctx;
			r_ctx = nullptr;
		}

		if (currentPipeline) {
			delete currentPipeline;
			currentPipeline = nullptr;
		}
	}



	void RendererProcessor::Run()
	{
		currentPipeline->Render(r_ctx, cameras);
	}


}
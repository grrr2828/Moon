#include "RendererProcessor.h"
#include "RendererGL.h"

namespace moon {

	RendererProcessor::RendererProcessor()
	{
		r_ctx = new RendererContextGL();
		r_ctx->Init();



		//test
		currentPipeline = new RendererPipeline();
	}

	RendererProcessor::~RendererProcessor()
	{

	}



	void RendererProcessor::Run()
	{
		currentPipeline->Render(r_ctx, cameras);
	}


}
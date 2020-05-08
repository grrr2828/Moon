#include "RendererPipeline.h"
#include "CullResults.h"

namespace moon {


	RendererPipeline::RendererPipeline()
	{

	}

	RendererPipeline::~RendererPipeline()
	{

	}

	void RendererPipeline::Render(RendererContextI* context, std::vector<Camera*>& cameras)
	{
		int size = cameras.size();

		for (int i = 0; i < size; i++)
		{
			auto camera = cameras[i];
			CullResults::Cull(camera);
		}

		auto visibleRenderers = CullResults::visibleRenderers;


		context->Submit();
	}

}
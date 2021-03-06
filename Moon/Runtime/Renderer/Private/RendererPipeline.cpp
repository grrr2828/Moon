#include "RendererPipeline.h"
#include "CullResults.h"

namespace moon {


	RendererPipeline::RendererPipeline()
	{
		commandBuffer = new CommandBuffer();
	}

	RendererPipeline::~RendererPipeline()
	{
		if (commandBuffer) {
			commandBuffer->Clear();
			delete commandBuffer;
			commandBuffer = nullptr;
		}

	}

	void RendererPipeline::DrawRenderers(std::vector<Renderer*>& renderers)
	{

	}

	void RendererPipeline::Render(RendererContextI* context, std::vector<Camera*>& cameras)
	{
		/*int size = cameras.size();

		for (int i = 0; i < size; i++)
		{
			auto camera = cameras[i];
			CullResults::Cull(camera);
		}*/



		CullResults::Cull(context, nullptr);

		auto visibleRenderers = CullResults::visibleRenderers;
		for (auto &renderer : visibleRenderers)
		{
			if (renderer) {
				renderer->Draw(context, commandBuffer);
			}
		}


		commandBuffer->Submit();
	}

}
#pragma once

#include <vector>

#include "Renderer.h"
#include "Camera.h"
#include "RendererContextI.h"
#include "CommandBuffer.h"

namespace moon {

	class  RendererPipeline
	{
	public:
		RendererPipeline();
		~RendererPipeline();

		void Render(RendererContextI* context, std::vector<Camera*>& cameras);

		virtual void DrawRenderers(std::vector<Renderer*>& renderers);

	private:

		CommandBuffer* commandBuffer = nullptr;

	};


}
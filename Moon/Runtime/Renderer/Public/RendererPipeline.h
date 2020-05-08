#pragma once

#include <vector>

#include "Renderer.h"
#include "Camera.h"
#include "RendererContextI.h"

namespace moon {

	class  RendererPipeline
	{
	public:
		RendererPipeline();
		~RendererPipeline();

		void Render(RendererContextI* context, std::vector<Camera*>& cameras);

	private:


	};


}
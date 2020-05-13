#pragma once

#include <vector>

#include "Renderer.h"
#include "Camera.h"


namespace moon {

	class CullResults
	{
	public:
		static std::vector<Renderer*> visibleRenderers;

		static void Cull(RendererContextI* context, Camera* camera);

	};
}
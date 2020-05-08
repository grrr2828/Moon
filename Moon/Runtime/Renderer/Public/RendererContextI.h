#pragma once

#include <vector>

#include "GraphicsEnums.h"
#include "Color.h"
#include "Renderer.h"

namespace moon {

	struct RendererContextI
	{
		virtual void Init() {};
		
		virtual RendererType GetRendererType() const { return RendererType::Count; };

		virtual void BufferClear(const Color& color) {};

		virtual void DrawRenderers(std::vector<Renderer*> &renderers);

		virtual void Submit();

		void AddCommand(RendererCommand* cmd);

		std::vector<RendererCommand*> renderQueue;
	};

}
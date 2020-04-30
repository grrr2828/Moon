#pragma once

#include <vector>

#include "Renderer.h"

namespace moon {

	class  RendererPipeline
	{
	public:
		 RendererPipeline();
		~ RendererPipeline();

		void AddRender(Renderer* render);
		void RemoveRender(Renderer* render);

		void Render();

		int depth;
	private:

		std::vector<Renderer*> _renderList;

	};


}
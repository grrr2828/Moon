#pragma once

#include <vector>

#include "Renderer.h"
#include "CommandBuffer.h"

namespace moon {

	class  RendererPipeline
	{
	public:
		 RendererPipeline();
		~ RendererPipeline();

		void AddRender(Renderer* render);
		void RemoveRender(Renderer* render);

		void AddCommandPre(Command* cmd);
		void AddCommandPost(Command* cmd);

		void Render();

		int depth;
	private:

		std::vector<Renderer*> _renderList;

		CommandBuffer _cmdPre;
		CommandBuffer _cmdSubmit;
		CommandBuffer _cmdPost;

	};


}
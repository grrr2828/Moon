#include "RendererContextI.h"

namespace moon {


	void RendererContextI::DrawRenderers(std::vector<Renderer*>& renderers)
	{

	}


	void RendererContextI::AddCommand(RendererCommand* cmd)
	{
		//cmd->r_ctx = this;
		renderQueue.push_back(cmd);
	}


	void RendererContextI::Submit()
	{
		int size = renderQueue.size();

		for (int i = 0; i < size; i++)
		{
			//auto cmd = renderQueue[i];
			//cmd->ExecuteCommand();
		}

		renderQueue.clear();
	}
}
#include "RendererContextI.h"
#include "Command.h"

namespace moon {

	void RendererContextI::AddCommand(RendererCommand* cmd)
	{
		renderQueue.push_back(cmd);
	}

	void RendererContextI::Submit()
	{
		int size = renderQueue.size();

		for (int i = 0; i < size; i++)
		{
			auto cmd = renderQueue[i];
			cmd->ExecuteCommand();
		}

		renderQueue.clear();
	}
}
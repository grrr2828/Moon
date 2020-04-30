#include "RendererProcessor.h"
#include "RendererGL.h"

namespace moon {

	RendererProcessor::RendererProcessor()
	{
		r_ctx = new RendererContextGL();





		//test
		RendererPipeline* pipeline = new RendererPipeline();
		auto cmd = new BufferClearCommand();
		cmd->r_ctx = r_ctx;
		cmd->color.SetColor(0.5f, 0.3f, 0.4f, 1.0f);

		pipeline->AddCommandPre(cmd);

		AddPipeline(pipeline);
		//==================================

	}

	RendererProcessor::~RendererProcessor()
	{
	
	}

	void RendererProcessor::AddPipeline(RendererPipeline* pipeline)
	{
		_pipelineList.push_back(pipeline);
	}

	void RendererProcessor::Run()
	{
		int size = _pipelineList.size();

		for (int i = 0; i < size; i++)
		{
			_pipelineList[i]->Render();
		}
	}


}
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
		pipeline->AddCommandPre(cmd);

		AddPipeline(pipeline);

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

		for (size_t i = 0; i < size; i++)
		{
			_pipelineList[i]->Render();
		}
	}


}
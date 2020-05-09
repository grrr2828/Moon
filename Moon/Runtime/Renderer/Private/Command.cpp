#include "Command.h"

namespace moon {

	//RendererCommand
	RendererCommand::RendererCommand()
	{
	
	}

	RendererCommand::~RendererCommand()
	{
		indices = nullptr;
		vertices = nullptr;
	}

	void RendererCommand::PrepareDraw(RendererContextI* context, Mesh* mesh)
	{
		if(indices == nullptr) {
			
		}
	}

	void RendererCommand::ExecuteCommand()
	{

	}


	//BufferClearCommand
	void BufferClearCommand::ExecuteCommand()
	{
		//r_ctx->BufferClear(color);
	}



	//VertexBufferCommand
	void VertexBufferCommand::ExecuteCommand()
	{

	}

}
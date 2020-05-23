#include "Command.h"
#include "Mesh.h"

namespace moon {

	//RendererCommand
	RendererCommand::RendererCommand()
	{
	
	}

	RendererCommand::~RendererCommand()
	{
		
	}

	void RendererCommand::Init(Mesh* mesh, Buffer* indices, Shader* shader)
	{
		_shader = shader;
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
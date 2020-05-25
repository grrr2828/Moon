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

	void RendererCommand::Init(Mesh* mesh, const std::vector<Material*>& materials)
	{
		_mesh = mesh;
		_materials = materials;
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
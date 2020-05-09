#include "Command.h"
#include "Mesh.h"

namespace moon {

	//RendererCommand
	RendererCommand::RendererCommand()
	{
	
	}

	RendererCommand::~RendererCommand()
	{
		if (indicesBuffer) {
			delete indicesBuffer;
			indicesBuffer = nullptr;
		}

		if (verticesBuffer) {
			delete verticesBuffer;
			verticesBuffer = nullptr;
		}
	}

	void RendererCommand::PrepareDraw(RendererContextI* context, Mesh* mesh)
	{
		if(indicesBuffer == nullptr ) {
			indicesBuffer = context->CreateBuffer();

			auto indices = mesh->GetIndices();
			indicesBuffer->UpdateData(indices, mesh->indicesSize);
		}

		if (verticesBuffer == nullptr ) {
			verticesBuffer = context->CreateBuffer();

			auto verts = mesh->GetVertices();
			verticesBuffer->UpdateData(verts, mesh->verticesSize);

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
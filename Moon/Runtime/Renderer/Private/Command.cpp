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

	void RendererCommand::PrepareDraw(RendererContextI* context, Mesh* mesh, Shader* shader)
	{
		_context = context;

		/*if(indicesBuffer == nullptr ) {
			indicesBuffer = _context->CreateBuffer();

			auto indices = mesh->GetIndices();
			indicesBuffer->UpdateData(indices, mesh->indicesSize);
		}*/

		if (verticesBuffer == nullptr ) {
			verticesBuffer = _context->CreateBuffer();

			float* verts = mesh->GetVertices();
			verticesBuffer->UpdateData(verts, mesh->verticesSize);
		}

		

		_shader = shader;
	}

	void RendererCommand::ExecuteCommand()
	{
		_context->Draw(verticesBuffer, indicesBuffer, _shader);
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
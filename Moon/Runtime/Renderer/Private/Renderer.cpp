#include "Renderer.h"
#include "Context.h"
#include "RendererPipeline.h"
#include "Shader.h"

namespace moon {

	//Renderer
	Renderer::Renderer()
	{
		
	}

	Renderer::~Renderer()
	{
		if (_mesh) {

			delete _mesh;
			_mesh = nullptr;

		}

		_rendererCmdList.clear();
	}

	void Renderer::SetMesh(Mesh* mesh)
	{
		_mesh = mesh;
	}

	void Renderer::SetShader(Shader* shader)
	{
		_shader = shader;
	}


	void Renderer::Draw(RendererContextI* context)
	{
		if (_rendererCmdList.size() == 0) {
			
			int count = _mesh->subMeshCount;
			int subMeshOffSet = 0;

			auto indicesVec = _mesh->GetIndicesVec();

			for (size_t i = 0; i < count; i++)
			{
				auto cmd = context->CreateRendererCommand();
				auto indices = indicesVec[i];
				cmd->Init(_mesh, indices, _shader);
				_rendererCmdList.push_back(cmd);

				subMeshOffSet += indices->size;
			}

			
		}

		int s = _rendererCmdList.size();
		for (size_t i = 0; i < s; i++)
		{
			context->AddCommand(_rendererCmdList[i]);
		}
	}

}
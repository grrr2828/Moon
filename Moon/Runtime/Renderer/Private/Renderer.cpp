#include "Renderer.h"
#include "Context.h"
#include "RendererPipeline.h"
#include "Shader.h"

namespace moon {

	//Renderer
	Renderer::Renderer()
	{
		materials.resize(MAX_VAL_COUNT);
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

	void Renderer::SetMaterial(Material* material, int index)
	{
		materials[index] = material;
	}


	void Renderer::Draw(RendererContextI* context, CommandBuffer* commandBuffer)
	{
		if (_rendererCmdList.size() == 0) {
			
			auto cmd = context->CreateRendererCommand();
			cmd->Init(_mesh, materials);
			_rendererCmdList.push_back(cmd);
		}

		int s = _rendererCmdList.size();
		for (size_t i = 0; i < s; i++)
		{
			commandBuffer->Add(_rendererCmdList[i]);
		}
	}

}
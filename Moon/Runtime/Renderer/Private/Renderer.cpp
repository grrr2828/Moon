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

		if (_command) {

			delete _command;
			_command = nullptr;

		}
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

		if (_command == nullptr) {
			_command = context->CreateRendererCommand();
			_command->Init(_mesh, _shader);
		}
	
		context->AddCommand(_command);
	}

}
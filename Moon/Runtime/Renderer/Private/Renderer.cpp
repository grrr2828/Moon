#include "Renderer.h"
#include "Context.h"
#include "RendererPipeline.h"

namespace moon {


	//Renderer
	Renderer::Renderer()
	{
		_command = new RendererCommand();
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


	void Renderer::Draw(RendererContextI* context)
	{
		_command->PrepareDraw(context, _mesh);
		
		context->AddCommand(_command);
	}

}
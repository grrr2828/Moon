#include "Renderer.h"
#include "Context.h"

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


	void Renderer::Draw()
	{

	}

}
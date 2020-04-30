#include "Renderer.h"
#include "Context.h"

namespace moon {


	//RendererCommand
	void RendererCommand::ExecuteCommand()
	{
	
	}


	//BufferClearCommand
	void BufferClearCommand::ExecuteCommand()
	{
		r_ctx->BufferClear(color);
	}



	//Renderer
	Renderer::Renderer()
	{
	
	}

	Renderer::~Renderer()
	{
		if ( _mesh ) {
				
			delete _mesh;
			_mesh = nullptr;

		}
	}

	

}
#include "Renderer.h"

namespace moon {

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
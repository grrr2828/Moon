#pragma once

#include "Mesh.h"
#include "Command.h"

namespace moon {

	class RendererContextI;
	

	class Renderer
	{
	public:
		Renderer();
		~Renderer();

		void Draw(RendererContextI* context);
	private:

		Mesh* _mesh;

		RendererCommand* _command;

	};

}
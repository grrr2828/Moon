#pragma once

#include "Mesh.h"
#include "Command.h"

namespace moon {
	

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
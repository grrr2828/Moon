#pragma once

#include "Mesh.h"
#include "Command.h"

namespace moon {

	class Renderer
	{
	public:
		Renderer();
		~Renderer();

		void Draw();
	private:

		Mesh* _mesh;

		RendererCommand* _command;

	};

}
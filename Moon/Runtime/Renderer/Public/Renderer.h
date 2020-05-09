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

		void SetMesh(Mesh* mesh);
	private:

		Mesh* _mesh;

		RendererCommand* _command;

	};

}
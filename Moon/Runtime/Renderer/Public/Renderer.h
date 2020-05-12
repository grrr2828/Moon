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

		void SetShader( Shader* shader );
	private:

		Mesh* _mesh;

		Shader* _shader;

		RendererCommand* _command;

	};

}
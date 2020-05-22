#pragma once

#include <vector>

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

		Mesh* _mesh = nullptr;

		Shader* _shader = nullptr;

		std::vector<RendererCommand*> _rendererCmdList;
	};

}
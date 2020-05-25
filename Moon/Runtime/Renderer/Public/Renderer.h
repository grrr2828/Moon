#pragma once

#include <vector>

#include "Mesh.h"
#include "Command.h"
#include "CommandBuffer.h"
#include "Material.h"

namespace moon {
	
	class Renderer
	{
	public:
		enum {

			MAX_VAL_COUNT = 4

		};

		Renderer();
		~Renderer();

		void Draw(RendererContextI* context, CommandBuffer* commandBuffer);

		void SetMesh(Mesh* mesh);

		void SetMaterial(Material* material, int index = 0);
	private:

		Mesh* _mesh = nullptr;


		std::vector<Material*> materials;

		std::vector<RendererCommand*> _rendererCmdList;
	};

}
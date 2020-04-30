#pragma once

#include "Mesh.h"

namespace moon {

	class Renderer
	{
	public:
		Renderer();
		~Renderer();

	private:

		Mesh* _mesh;
	};

}
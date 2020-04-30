#pragma once

#include <vector>
#include "Vector.h"

namespace moon {

	class Mesh
	{
	public:
		Mesh();
		~Mesh();

		void SetIndices(int indices[]);

		void SetVertices(Vector vertices[]);

	private:

		std::vector<int> _indices;
		std::vector<Vector> _vertices;

	};

}

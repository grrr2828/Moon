#pragma once

#include <vector>
#include "Vector.h"

namespace moon {

	class Mesh
	{
	public:
		Mesh();
		~Mesh();

		void SetIndices(int indices[], int size);

		void SetVertices(Vector vertices[], int size);

		std::vector<int> GetIndices()
		{
			return _indices;
		}

		std::vector<Vector> GetVertices()
		{
			return _vertices;
		}
	private:

		std::vector<int> _indices;
		std::vector<Vector> _vertices;

	};

}

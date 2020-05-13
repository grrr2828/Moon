#pragma once

#include <vector>
#include "Vector.h"
#include "Color.h"

namespace moon {

	

	class Mesh
	{
	public:
		Mesh();
		~Mesh();

		void SetIndices(int* indices, int size);
		void SetVertices(float* vertices, int size);

		int* GetIndices()
		{
			return _indices;
		}

		float* GetVertices()
		{
			return _vertices;
		}

		int indicesSize;
		int verticesSize;
	private:

		int* _indices = nullptr;
		float* _vertices = nullptr;
		float* uv = nullptr;
		Color* iColors = nullptr;
	};

}

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
		void SetColors(Color* colors, int size);

		int* GetIndices()
		{
			return _indices;
		}

		float* GetVertices()
		{
			return _vertices;
		}

		Color* GetColors()
		{
			return _iColors;
		}

		int indicesSize;
		int verticesSize;
		int colorsSize;

		int vectCount;
	private:

		int* _indices = nullptr;
		float* _vertices = nullptr;
		float* uv = nullptr;
		Color* _iColors = nullptr;
	};

}

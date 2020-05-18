#pragma once

#include <vector>


#include "Vector.h"
#include "Color.h"
#include "VertexLayout.h"

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

		float* GetUVs()
		{
			return uv;
		}

		VertexLayout* GetVertexLayout()
		{
			return vertexLayout;
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

		VertexLayout* vertexLayout = nullptr;
	};

}

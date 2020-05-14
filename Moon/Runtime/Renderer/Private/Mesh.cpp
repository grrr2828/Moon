#include "Mesh.h"

namespace moon {

	Mesh::Mesh() {

	}

	Mesh::~Mesh() {

	}

	void Mesh::SetIndices(int* indices, int size)
	{
		
		_indices = indices;
		indicesSize = size;

	}

	void Mesh::SetVertices(float* vertices, int size)
	{
		
		_vertices = vertices;
		verticesSize = size;

		vectCount = size / sizeof(_vertices[0]) / 3;


	}

	void Mesh::SetColors(Color* colors, int size)
	{
		_iColors = colors;
		colorsSize = size;
	}


}
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
	}


}
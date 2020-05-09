#include "Mesh.h"

namespace moon {

	Mesh::Mesh() {

	}

	Mesh::~Mesh() {

	}

	void Mesh::SetIndices(int indices[], int size)
	{
		_indices.clear();


		for (int i = 0; i < size; i++)
		{
			_indices.push_back(indices[i]);
		}
	}

	void Mesh::SetVertices(Vector vertices[], int size)
	{
		_vertices.clear();

		for (int i = 0; i < size; i++)
		{
			_vertices.push_back(vertices[i]);
		}
	}


}
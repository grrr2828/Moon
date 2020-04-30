#include "Mesh.h"

namespace moon {

	Mesh::Mesh() {
	
	}

	Mesh::~Mesh() {
	
	}

	void Mesh::SetIndices(int indices[])
	{
		_indices.clear();

		int size = sizeof(indices)/sizeof(indices[0]);

		for (size_t i = 0; i < size; i++)
		{
			_indices.push_back(indices[i]);
		}
	}

	void Mesh::SetVertices(Vector vertices[])
	{
		_vertices.clear();

		int size = sizeof(vertices) / sizeof(vertices[0]);

		for (size_t i = 0; i < size; i++)
		{
			_vertices.push_back(vertices[i]);
		}
	}

	
}
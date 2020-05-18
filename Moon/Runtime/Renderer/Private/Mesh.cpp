#include "Mesh.h"

namespace moon {

	Mesh::Mesh() {
		vertexLayout = new VertexLayout();
	}

	Mesh::~Mesh() {
		delete vertexLayout;
		vertexLayout = nullptr;
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

		vertexLayout->SetAttribute("a_postion", vectCount * 3, 3, 0, VertexLayout::AttributeType::Vertex);
	}

	void Mesh::SetColors(Color* colors, int size)
	{
		_iColors = colors;
		colorsSize = size;
	}


}
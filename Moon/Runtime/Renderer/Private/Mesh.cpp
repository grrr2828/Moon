#include "Mesh.h"

namespace moon {

	Buffer::Buffer()
	{
	
	}

	Buffer::~Buffer()
	{
		data = nullptr;
	}

	Mesh::Mesh() {
		vertexLayout = new VertexLayout();
		_indicesArray.resize(MAX_VAL_COUNT);
	}

	Mesh::~Mesh() {
		delete vertexLayout;
		vertexLayout = nullptr;

		if (_vertices) {
			delete _vertices;
			_vertices = nullptr;
		}

		if (_iColors) {
			delete _iColors;
			_iColors = nullptr;
		}

		_indicesArray.clear();

		if (uv) {
			delete uv;
			uv = nullptr;
		}
	}

	void Mesh::SetIndices(int* data, int size, int index)
	{

		Buffer* indices = _indicesArray[index];
		if (indices == nullptr) {
			indices = new Buffer();
			indices->format = Buffer::DataFormat::INT;

			_indicesArray[index] = indices;

			subMeshCount++;
		}

		indices->data = data;
		indices->size = size / sizeof(data[0]);
	}

	void Mesh::SetVertices(float* data, int size)
	{
		if (_vertices == nullptr ) {
			_vertices = new Buffer();
			_vertices->format = Buffer::DataFormat::FLOAT;
		}

		_vertices->data = data;
		_vertices->size = size / sizeof(data[0]);

	
		vertexLayout->SetAttribute("a_postion", _vertices->size, 3, 0, VertexLayout::AttributeType::Vertex);
	}

	void Mesh::SetColors(Color* colors, int size)
	{
		if (_iColors == nullptr) {
			_iColors = new Buffer();
			_iColors->format = Buffer::DataFormat::COLOR;
		}

		_iColors->data = colors;
		_iColors->size = size / sizeof(colors[0]);

		vertexLayout->SetAttribute("a_color", _iColors->size * 3, 3, 1, VertexLayout::AttributeType::Color);
	}

	void Mesh::SetUVs(float* data, int size)
	{
		if (uv == nullptr) {
			uv = new Buffer();
			uv->format = Buffer::DataFormat::FLOAT;
		}

		uv->data = data;
		uv->size = size / sizeof(data[0]);

		vertexLayout->SetAttribute("a_uv", uv->size, 2, 2, VertexLayout::AttributeType::UV);

	}


}
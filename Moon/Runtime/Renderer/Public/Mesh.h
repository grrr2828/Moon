#pragma once

#include <vector>


#include "Vector.h"
#include "Color.h"
#include "VertexLayout.h"

namespace moon {


	class Buffer
	{
	public:

		enum DataFormat
		{
			FLOAT,
			INT,
			COLOR
		};

		Buffer();
		~Buffer();

	public:
		void* data = nullptr;
		int size;
		DataFormat format;
	};


	class Mesh
	{
	public:
		Mesh();
		~Mesh();

		void SetIndices(int* data, int size);
		void SetVertices(float* data, int size);
		void SetColors(Color* data, int size);
		void SetUVs(float* data, int size);

		Buffer* GetIndices()
		{
			return _indices;
		}

		Buffer* GetVertices()
		{
			return _vertices;
		}

		Buffer* GetColors()
		{
			return _iColors;
		}

		Buffer* GetUVs()
		{
			return uv;
		}

		VertexLayout* GetVertexLayout()
		{
			return vertexLayout;
		}

	private:

		Buffer* _indices = nullptr;
		Buffer* _vertices = nullptr;
		Buffer* uv = nullptr;
		Buffer* _iColors = nullptr;

		VertexLayout* vertexLayout = nullptr;
	};

}

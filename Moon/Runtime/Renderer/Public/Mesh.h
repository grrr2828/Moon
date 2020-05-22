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

		enum {

			MAX_VAL_COUNT = 4

		};

		Mesh();
		~Mesh();

		void SetIndices(int* data, int size, int index = 0);
		void SetVertices(float* data, int size);
		void SetColors(Color* data, int size);
		void SetUVs(float* data, int size);

		const std::vector<Buffer*>& GetIndicesVec()
		{
			return _indicesArray;
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

		int subMeshCount = 0;
	private:
		std::vector<Buffer*> _indicesArray;

		Buffer* _vertices = nullptr;
		Buffer* uv = nullptr;
		Buffer* _iColors = nullptr;

		VertexLayout* vertexLayout = nullptr;

	};

}

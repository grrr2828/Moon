#pragma once

#include "RendererContextI.h"
#include <glad/glad.h>


namespace moon {

	class BufferGL : public Buffer
	{

	public:

		BufferGL();
		~BufferGL();

		void UpdateData(void* data, std::size_t size) override;
	
	private:

		GLuint _buffer = 0;
		std::size_t _bufferAllocated = 0;
		char* _data = nullptr;
	};

	class RendererContextGL : public RendererContextI
	{

	public:
		
		RendererContextGL();

		~RendererContextGL();

		RendererType GetRendererType() const override;

		void ClearTarget(const Color& color) override;

		Buffer* CreateBuffer() override;

		void ReleaseBuffer(Buffer* buffer) override;
	};

}

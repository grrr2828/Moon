#pragma once

#include "RendererContextI.h"
#include <glad/glad.h>


namespace moon {

	class BufferGL : public Buffer
	{

	public:

		BufferGL();
		~BufferGL();


	private:

		GLuint _buffer = 0;
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

#include "RendererGL.h"

namespace moon {


	BufferGL::BufferGL()
	{
		glBindBuffer(1, _buffer);
	}

	BufferGL::~BufferGL()
	{
		if (_buffer)
			glDeleteBuffers(1, &_buffer);
	}





	RendererContextGL::RendererContextGL()
	{
		
	}

	RendererContextGL::~RendererContextGL()
	{
	
	}

	void RendererContextGL::ClearTarget(const Color& color)
	{
		float r = (float)color.r() / 255;
		float g = (float)color.g() / 255;
		float b = (float)color.b() / 255;
		float a = (float)color.a() / 255;

		glClearColor( r, g, b, a );
		glClear(GL_COLOR_BUFFER_BIT);
	}

	Buffer* RendererContextGL::CreateBuffer()
	{
		return new BufferGL();
	}

	void RendererContextGL::ReleaseBuffer(Buffer* buffer)
	{
		if (buffer) {
			delete buffer;
			buffer = nullptr;
		}
	}

	RendererType RendererContextGL::GetRendererType() const
	{
		return RendererType::OpenGL;
	}
	
}
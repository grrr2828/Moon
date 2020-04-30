#include "RendererGL.h"
#include <GLFW/glfw3.h>

namespace moon {

	RendererContextGL::RendererContextGL()
	{
		
	}

	RendererContextGL::~RendererContextGL()
	{
	
	}

	void RendererContextGL::BufferClear(const Color& color)
	{
		float r = (float)color.r() / 255;
		float g = (float)color.g() / 255;
		float b = (float)color.b() / 255;
		float a = (float)color.a() / 255;

		glClearColor( r, g, b, a );
		glClear(GL_COLOR_BUFFER_BIT);
	}

	RendererType RendererContextGL::GetRendererType() const
	{
		return RendererType::OpenGL;
	}
	
}
#include "RendererGL.h"
#include <GLFW/glfw3.h>

namespace moon {

	RendererContextGL::RendererContextGL()
	{
		
	}

	RendererContextGL::~RendererContextGL()
	{
	
	}

	void RendererContextGL::BufferClear()
	{
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
	}

	RendererType RendererContextGL::GetRendererType() const
	{
		return RendererType::OpenGL;
	}
	
}
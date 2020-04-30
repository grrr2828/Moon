#include "RendererGL.h"


namespace moon {

	RendererContextGL::RendererContextGL()
	{
		
	}

	RendererContextGL::~RendererContextGL()
	{
	
	}

	RendererType RendererContextGL::GetRendererType() const
	{
		return RendererType::OpenGL;
	}
	
}
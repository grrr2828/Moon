#pragma once

namespace moon {

	
	enum MeshTopology
	{
		Triangles = 0,
		Quads = 2,
		Lines = 3,
		LineStrip = 4,
		Points = 5
	};

	enum RendererType
	{
		Noop,         //!< No rendering.
		Direct3D9,    //!< Direct3D 9.0
		Direct3D11,   //!< Direct3D 11.0
		Direct3D12,   //!< Direct3D 12.0
		Gnm,          //!< GNM
		Metal,        //!< Metal
		Nvn,          //!< NVN
		OpenGLES,     //!< OpenGL ES 2.0+
		OpenGL,       //!< OpenGL 2.1+
		Vulkan,       //!< Vulkan

		Count
	};

}
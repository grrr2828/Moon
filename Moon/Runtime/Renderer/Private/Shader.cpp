#include "Shader.h"

namespace moon {

	Shader::Shader()
	{
	
	}

	Shader::~Shader()
	{
	
	}

	void Shader::CompileShader(const char* vertexShaderSource, const char* fragmentShaderSourcece)
	{
		_vertexShaderSource = vertexShaderSource;
		_fragmentShaderSource = fragmentShaderSourcece;
	}

}
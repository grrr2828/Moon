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

	void Shader::SetBool(const std::string& name, bool value)
	{
	
	}

	void Shader::SetInt(const std::string& name, int value)
	{
	
	}

	void Shader::SetFloat(const std::string& name, float* value)
	{
		UniformInfo info;
		info.data = value;
		info.type = UniformInfo::UniformDataType::FLOAT;

		_uniformInfos[name] = info;
	}

	void Shader::SetColor(const std::string& name, Color& value)
	{
		UniformInfo info;
		info.data = value;
		info.type = UniformInfo::UniformDataType::COLOR;

		_uniformInfos[name] = info;
	}

}
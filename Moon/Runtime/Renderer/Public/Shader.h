#pragma once

#include <string>

namespace moon {

	
	class Shader
	{
	public:
		Shader();
		~Shader();

		virtual void CompileShader(const char* vertexShaderSource, const char* sourfragmentShaderSourcece);

		virtual void Use() {};
	private:

		const char* _vertexShaderSource = nullptr;
		const char* _fragmentShaderSource = nullptr;
	};
}

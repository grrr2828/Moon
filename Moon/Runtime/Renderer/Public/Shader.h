#pragma once

#include <string>
#include <unordered_map>

#include "Color.h"
#include "Texture.h"

namespace moon {

	struct UniformInfo
	{
		enum UniformDataType
		{
			BOOL,
			INT,
			FLOAT,
			COLOR
		};

		int location = -1;
		void* data;
		bool isArray = false;
		int count = 0;

		UniformDataType type;
	};
	
	class Shader
	{
	public:
		Shader();
		~Shader();

		virtual void CompileShader(const char* vertexShaderSource, const char* sourfragmentShaderSourcece);

		virtual void Use() {};

		virtual void SetBool(const std::string& name, bool value);
		virtual void SetInt(const std::string& name, int value);
		virtual void SetFloat(const std::string& name, float* value);
		virtual void SetColor(const std::string& name, Color& value);

		virtual void FlushUniformInfos() {};

		virtual void SetMainTexture(Texture2D* mainTexture)
		{
			_mainTexture = mainTexture;
		}

		Texture2D* _mainTexture;
	protected:

		std::unordered_map<std::string, UniformInfo> _uniformInfos;

	private:


		const char* _vertexShaderSource = nullptr;
		const char* _fragmentShaderSource = nullptr;
	};
}

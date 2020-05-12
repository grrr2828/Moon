#pragma once

#include <glad/glad.h>


#include "RendererContextI.h"
#include "Shader.h"

namespace moon {

	//BufferGL
	class BufferGL : public Buffer
	{

	public:

		BufferGL();
		~BufferGL();

		void Refresh() override;

		void UpdateData(void* data, std::size_t size) override;

	private:

		GLuint buffer = 0;
		GLuint vao;
	};


	//ShaderGL
	class ShaderGL : public Shader
	{

	public:
		
		ShaderGL();
		~ShaderGL();
	
		void CompileShader(const std::string& vertexShaderSource, const std::string& sourfragmentShaderSourcece) override;

		void Use() override;
	private:

		GLuint CreateShader(GLenum type, const std::string& source);
		GLuint shaderProgram = 0;
	};


	//RendererContextGL
	class RendererContextGL : public RendererContextI
	{

	public:
		
		RendererContextGL();

		~RendererContextGL();

		RendererType GetRendererType() const override;

		void ClearTarget(const Color& color) override;

		Buffer* CreateBuffer() override;

		Shader* CreateShader() override;

		void Draw(Buffer* verts, Buffer* indices, Shader* shader) override;
	};

}

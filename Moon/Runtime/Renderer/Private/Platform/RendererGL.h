#pragma once

#include <glad/glad.h>


#include "RendererContextI.h"
#include "Shader.h"
#include "Command.h"

namespace moon {

	

	//ShaderGL
	class ShaderGL : public Shader
	{

	public:
		
		ShaderGL();
		~ShaderGL();
	
		void CompileShader(const char* vertexShaderSource, const char* sourfragmentShaderSourcece) override;

		void Use() override;
	private:

		GLuint CreateShader(GLenum type, const char* source);
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

		Shader* CreateShader() override;

		RendererCommand* CreateRendererCommand() override;

	};

	class RendererCommandGL : public RendererCommand
	{

	public:

		RendererCommandGL();
		~RendererCommandGL();

		void Init(Mesh* mesh, Shader* shader) override;

		void ExecuteCommand() override;

	private:

		GLuint verticesBuffer = 0;
		GLuint indicesBuffer = 0;
		GLuint vao = 0;
		int drawVertCount = 0;

		float* finalVertices = nullptr;
	};

}

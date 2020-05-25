#pragma once

#include <glad/glad.h>


#include "RendererContextI.h"
#include "Shader.h"
#include "Command.h"
#include "Mesh.h"
#include "Texture.h"

namespace moon {

	//ShaderGL
	class ShaderGL : public Shader
	{

	public:
		
		ShaderGL();
		~ShaderGL();
	
		void CompileShader(const char* vertexShaderSource, const char* sourfragmentShaderSourcece) override;

		void Use() override;

		void SetBool(const std::string& name, bool value)override;
		void SetInt(const std::string& name, int value)override;
		void SetFloat(const std::string& name, float* value)override;
		void SetColor(const std::string& name, Color& value) override;

		void FlushUniformInfos() override;

		void SetMainTexture(Texture2D* texture) override;
	private:

		GLuint CreateShader(GLenum type, const char* source);
		GLuint shaderProgram = 0;
		GLuint mainTextureId = 0;
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

		Texture2D* CreateTexture2D() override;

	};

	class RendererCommandGL : public RendererCommand
	{

	public:

		RendererCommandGL();
		~RendererCommandGL();

		void Init(Mesh* mesh, const std::vector<Material*>& materials) override;

		void ExecuteCommand() override;

	protected:

		void FillBuffer(Buffer* source, float* buffer, int startIndex, int step, int num, int size);

	private:

		GLuint verticesBuffer = 0;
		GLuint vao = 0;


		GLuint* indicesBuffers;

		float* finalVertices = nullptr;
	};


	class Texture2DGL : public Texture2D
	{
	public:
		
		Texture2DGL();
		~Texture2DGL();
	private:

	};

	

}

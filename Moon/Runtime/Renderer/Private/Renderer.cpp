#include "Renderer.h"
#include "Context.h"
#include "RendererPipeline.h"
#include "Shader.h"

namespace moon {

	const char* vertexShaderSource = "#version 330 core\n"
		"layout (location = 0) in vec3 aPos;\n"
		"void main()\n"
		"{\n"
		"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
		"}\0";
	const char* fragmentShaderSource = "#version 330 core\n"
		"out vec4 FragColor;\n"
		"void main()\n"
		"{\n"
		"   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
		"}\n\0";



	//Renderer
	Renderer::Renderer()
	{
		_command = new RendererCommand();
	}

	Renderer::~Renderer()
	{
		if (_mesh) {

			delete _mesh;
			_mesh = nullptr;

		}

		if (_command) {

			delete _command;
			_command = nullptr;

		}
	}

	void Renderer::SetMesh(Mesh* mesh)
	{
		_mesh = mesh;
	}

	void Renderer::SetShader(Shader* shader)
	{
		_shader = shader;
	}


	void Renderer::Draw(RendererContextI* context)
	{
		if ( _shader == nullptr ) {
			Shader* shader = context->CreateShader();
			shader->CompileShader(vertexShaderSource, fragmentShaderSource);
			SetShader(shader);
		}

		_command->PrepareDraw(context, _mesh, _shader);
		
		context->AddCommand(_command);
	}

}
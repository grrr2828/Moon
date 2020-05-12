#include "RendererGL.h"

namespace moon {


	BufferGL::BufferGL()
	{
		glGenBuffers(1, &buffer);
		glGenVertexArrays(1, &vao);
	}

	BufferGL::~BufferGL()
	{
		if (buffer)
			glDeleteBuffers(1, &buffer);
	}


	void BufferGL::Refresh()
	{
		glBindVertexArray(vao);
	}


	void BufferGL::UpdateData(void* data, std::size_t size)
	{

		glBindVertexArray(vao);

		glBindBuffer(GL_ARRAY_BUFFER, buffer);
		glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		glBindVertexArray(0);
	}


	ShaderGL::ShaderGL()
	{
	
	}

	ShaderGL::~ShaderGL()
	{
		
		if ( shaderProgram ) {
			glDeleteProgram(shaderProgram);
		}
	}

	void ShaderGL::CompileShader(const std::string& vertexShaderSource, const std::string& fragmentShaderSourcece)
	{
		int vertShader = CreateShader(GL_VERTEX_SHADER, vertexShaderSource);
		int fragShader = CreateShader(GL_FRAGMENT_SHADER, fragmentShaderSourcece);

		int success = 0;
		char infoLog[512];
		shaderProgram = glCreateProgram();	
		glAttachShader(shaderProgram, vertShader);
		glAttachShader(shaderProgram, fragShader);
		glLinkProgram(shaderProgram);
		// check for linking errors
		glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
		if (!success) {
			glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		}

		glDeleteShader(vertShader);
		glDeleteShader(fragShader);
	}

	GLuint ShaderGL::CreateShader(GLenum type, const std::string& source)
	{
		GLuint shader = glCreateShader(type);

		const GLchar* sourceGL = reinterpret_cast<const GLchar*>(source.c_str());

		glShaderSource(shader, 1, &sourceGL, NULL);
		glCompileShader(shader);
		// check for shader compile errors
		int success;
		char infoLog[512];
		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(shader, 512, NULL, infoLog);
		}

		return shader;
	}

	void ShaderGL::Use()
	{
		glUseProgram(shaderProgram);
	}


	RendererContextGL::RendererContextGL()
	{
		
	}

	RendererContextGL::~RendererContextGL()
	{
	
	}

	void RendererContextGL::ClearTarget(const Color& color)
	{
		float r = (float)color.r() / 255;
		float g = (float)color.g() / 255;
		float b = (float)color.b() / 255;
		float a = (float)color.a() / 255;

		//glClearColor( r, g, b, a );
		//glClear(GL_COLOR_BUFFER_BIT);
	}

	Buffer* RendererContextGL::CreateBuffer()
	{
		return new BufferGL();
	}

	Shader* RendererContextGL::CreateShader()
	{
		return new ShaderGL();
	}

	RendererType RendererContextGL::GetRendererType() const
	{
		return RendererType::OpenGL;
	}

	void RendererContextGL::Draw(Buffer* verts, Buffer* indices, Shader* shader)
	{
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		verts->Refresh();
		shader->Use();

		glDrawArrays(GL_TRIANGLES, 0, 6);
	}
	
}
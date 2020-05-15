#include "RendererGL.h"
#include "Mesh.h"

namespace moon {


	ShaderGL::ShaderGL()
	{
	
	}

	ShaderGL::~ShaderGL()
	{
		
		if ( shaderProgram ) {
			glDeleteProgram(shaderProgram);
		}
	}

	void ShaderGL::CompileShader(const char* vertexShaderSource, const char* fragmentShaderSourcece)
	{
		Shader::CompileShader(vertexShaderSource, fragmentShaderSourcece);

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

	GLuint ShaderGL::CreateShader(GLenum type, const char* source)
	{
		GLuint shader = glCreateShader(type);

		const GLchar* sourceGL = reinterpret_cast<const GLchar*>(source);

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

	void ShaderGL::SetBool(const std::string& name, bool value)
	{
		Shader::SetBool(name, value);

		_uniformInfos[name].location = glGetUniformLocation(shaderProgram, name.c_str());
	}

	void ShaderGL::SetInt(const std::string& name, int value)
	{
		Shader::SetInt(name, value);

		_uniformInfos[name].location = glGetUniformLocation(shaderProgram, name.c_str());

	}

	void ShaderGL::SetFloat(const std::string& name, float* value)
	{
		Shader::SetFloat( name, value );

		_uniformInfos[name].location = glGetUniformLocation(shaderProgram, name.c_str());
	}

	void ShaderGL::SetColor(const std::string& name, Color& value)
	{
		Shader::SetColor( name, value );

		_uniformInfos[name].location = glGetUniformLocation(shaderProgram, name.c_str());
	}

	void ShaderGL::FlushUniformInfos()
	{
		for (auto iter = _uniformInfos.begin(); iter != _uniformInfos.end(); iter++)
		{
			UniformInfo info = iter->second;

			
			
			switch (info.type)
			{
			case UniformInfo::UniformDataType::FLOAT:
				{
					float* f = (float*)info.data;
					glUniform1f(info.location, *f);
				}

				break;
			case UniformInfo::UniformDataType::COLOR:
				{
					Color* color = (Color*)info.data;
					glUniform4f(info.location, color->r_float(), color->g_float(), color->b_float(), color->a_float());
				}
				break;

			}
		}
	}



	RendererContextGL::RendererContextGL()
	{
		
	}

	RendererContextGL::~RendererContextGL()
	{
	
	}

	void RendererContextGL::ClearTarget(const Color& color)
	{
		float r = color.r_float();
		float g = color.g_float();
		float b = color.b_float();
		float a = color.a_float();

		//glClearColor( r, g, b, a );
		//glClear(GL_COLOR_BUFFER_BIT);
	}

	Shader* RendererContextGL::CreateShader()
	{
		return new ShaderGL();
	}

	RendererCommand* RendererContextGL::CreateRendererCommand()
	{
		return new RendererCommandGL();
	}

	RendererType RendererContextGL::GetRendererType() const
	{
		return RendererType::OpenGL;
	}


	RendererCommandGL::RendererCommandGL()
	{

	}


	RendererCommandGL::~RendererCommandGL()
	{
		if (verticesBuffer)
			glDeleteBuffers(1, &verticesBuffer);

		if (finalVertices) {
			delete[] finalVertices;
		}

	}

	void RendererCommandGL::FilliColorsBuffer(Color* data, int size, float* buffer, int startIndex, int step)
	{
		int colorIndex = startIndex;
		for (int i = 0; i < size; i++)
		{
			auto c = data[i];
			buffer[colorIndex] = c.r_float();
			buffer[colorIndex + 1] = c.g_float();
			buffer[colorIndex + 2] = c.b_float();

			colorIndex += step;
		}
	}

	void RendererCommandGL::FillVerticesBuffer(float* data, int size, float* buffer, int startIndex, int step)
	{
		int vertIndex = startIndex;
		for (int i = 0; i < size; i++)
		{
			if (i != 0 && i % 3 == 0) {
				vertIndex += step;
			}

			auto v = data[i];
			buffer[vertIndex + i] = v;

		}
	}

	void RendererCommandGL::Init(Mesh* mesh, Shader* shader)
	{
		RendererCommand::Init(mesh, shader);

		glGenBuffers(1, &verticesBuffer);
		glGenBuffers(1, &indicesBuffer);

		glGenVertexArrays(1, &vao);
		
		glBindVertexArray(vao);

		auto iColors = mesh->GetColors();

		int colorLen = mesh->colorsSize / sizeof(iColors[0]);
		int verticesLen = mesh->verticesSize / sizeof(mesh->GetVertices()[0]);

		int len = verticesLen + colorLen * 3;
		finalVertices = new float[len];

		auto vertices = mesh->GetVertices();
		

		FillVerticesBuffer(vertices, verticesLen, finalVertices, 0, 3);
		FilliColorsBuffer(iColors, colorLen, finalVertices, 3, 6);

		
	
		for (size_t i = 0; i < len; i++)
		{
			float v = finalVertices[i];
			printf("%f \n", v);
		}

		drawVertCount = mesh->vectCount;


		glBindBuffer(GL_ARRAY_BUFFER, verticesBuffer);
		glBufferData(GL_ARRAY_BUFFER, sizeof(finalVertices[0]) * len, finalVertices, GL_STATIC_DRAW);


		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indicesBuffer);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, mesh->indicesSize, mesh->GetIndices(), GL_STATIC_DRAW);


		//vert
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		//icolor
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(1);
		
				
		glEnableVertexAttribArray(0);
		glBindVertexArray(0);

	}

	void RendererCommandGL::ExecuteCommand()
	{
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glBindVertexArray(vao);
		_shader->Use();
		_shader->FlushUniformInfos();
		

		glDrawElements(GL_TRIANGLES, drawVertCount, GL_UNSIGNED_INT, 0);
	}
	
}
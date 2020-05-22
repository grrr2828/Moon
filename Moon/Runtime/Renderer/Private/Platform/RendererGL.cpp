#include "RendererGL.h"

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

	Texture2D* RendererContextGL::CreateTexture2D()
	{
		return new Texture2DGL();
	}

	//RendererCommandGL
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

	void RendererCommandGL::FillBuffer(Buffer* source, float* buffer, int startIndex, int step, int num, int drawVertCount, int subMeshOffSet)
	{
		if (source == nullptr) {
			return;
		}

		int index = startIndex;

		if (source->format == Buffer::DataFormat::FLOAT) {
			int size = drawVertCount * num;
			float* value = (float*)source->data;
			int count = 0;

			subMeshOffSet *= num;
			for (size_t i = 0; i < size; i++)
			{
				if (i != 0 && i % num == 0) {
					index += step;
					count = 0;
				}

				auto v = value[i + subMeshOffSet];
				buffer[index + count] = v;
				count++;
			}
		}
		else if (source->format == Buffer::DataFormat::COLOR) {
			int size = drawVertCount;
			Color* value = (Color*)source->data;
			for (int i = 0; i < size; i++)
			{
				auto c = value[i + subMeshOffSet];
				buffer[index] = c.r_float();
				buffer[index + 1] = c.g_float();
				buffer[index + 2] = c.b_float();

				index += step;
			}
		}
	}

	

	void RendererCommandGL::Init(Mesh* mesh, Buffer* indices, int subMeshOffSet, Shader* shader)
	{
		RendererCommand::Init(mesh, indices, subMeshOffSet, shader);

		glGenBuffers(1, &verticesBuffer);
		glGenBuffers(1, &indicesBuffer);

		glGenVertexArrays(1, &vao);
		
		glBindVertexArray(vao);


		auto vertices = mesh->GetVertices();
		auto vertexLayout = mesh->GetVertexLayout();
		auto iColors = mesh->GetColors();
		auto uvs = mesh->GetUVs();

		drawVertCount = indices->size;

		const auto& attributes = vertexLayout->GetAttributes();

		int len = 0;
		for (const auto& it : attributes)
		{
			len += drawVertCount * it.num;
		}

		finalVertices = new float[len];


		glBindBuffer(GL_ARRAY_BUFFER, verticesBuffer);
		int stride = vertexLayout->stride;

		for (const auto& it : attributes)
		{
			Buffer* source = nullptr;

			switch (it.type)
			{
			case VertexLayout::AttributeType::Vertex:
				source = vertices;
				break;
			case VertexLayout::AttributeType::Color:
				source = iColors;
				break;
			case VertexLayout::AttributeType::UV:
				source = uvs;
				break;
			}
			
			FillBuffer(source, finalVertices, it.offSet, stride, it.num, drawVertCount, subMeshOffSet);
						
			glVertexAttribPointer(it.location, it.num, GL_FLOAT, GL_FALSE, stride * sizeof(float), (void*)(it.offSet * sizeof(float)));
			glEnableVertexAttribArray(it.location);
			
		}

		glBufferData(GL_ARRAY_BUFFER, sizeof(finalVertices[0]) * len, finalVertices, GL_STATIC_DRAW);

		for (size_t i = 0; i < len; i++)
		{
			float v = finalVertices[i];
			printf("%f \n", v);
		}

		int* d = (int*)indices->data;

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indicesBuffer);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices->size * sizeof(d[0]), d, GL_STATIC_DRAW);

	
		glEnableVertexAttribArray(0);
		glBindVertexArray(0);

	}

	void RendererCommandGL::ExecuteCommand()
	{
		//glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		//glClear(GL_COLOR_BUFFER_BIT);

		glBindVertexArray(vao);
		_shader->Use();
		_shader->FlushUniformInfos();
		

		glDrawElements(GL_TRIANGLES, drawVertCount, GL_UNSIGNED_INT, 0);
	}


	//Texture2DGL
	Texture2DGL::Texture2DGL()
	{
		
	}

	Texture2DGL::~Texture2DGL()
	{
	
	}
	
}
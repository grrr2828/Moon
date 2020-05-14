#include "CullResults.h"
#include "Shader.h"

namespace moon {

	std::vector<Renderer*> CullResults::visibleRenderers(0);

	float vertices[] = {
		// first triangle
		-0.9f, -0.5f, 0.0f,  // left 
		-0.0f, -0.5f, 0.0f,  // right
		-0.45f, 0.5f, 0.0f,  // top 
	};

	int indices[]{
		0,1,2
	};

	Color iColors[]{
		Color(1.0f, 0.0f, 0.0f),
		Color(0.0f, 1.0f, 0.0f),
		Color(0.0f, 0.0f, 1.0f),
	};

	const char* vertexShaderSource = "#version 330 core\n"
		"layout (location = 0) in vec3 aPos;\n"
		"layout (location = 1) in vec3 aColor;\n"
		"out vec3 ourColor;\n"
		"void main()\n"
		"{\n"
		"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
		"   ourColor = aColor;\n"
		"}\0";
	const char* fragmentShaderSource = "#version 330 core\n"
		"out vec4 FragColor;\n"
		"in vec3 ourColor;\n"
		"void main()\n"
		"{\n"
		"   FragColor = vec4(ourColor, 1.0);\n"
		"}\n\0";

	void CullResults::Cull(RendererContextI* context, Camera* camera)
	{
		//visibleRenderers.clear();


		if (visibleRenderers.size() == 0) {
			//test
			Renderer* r = new Renderer();


			Mesh* mesh = new Mesh();
			mesh->SetIndices(indices, sizeof(indices));
			mesh->SetVertices(vertices, sizeof(vertices));
			mesh->SetColors(iColors, sizeof(iColors));
			r->SetMesh(mesh);

			Shader* shader = context->CreateShader();
			shader->CompileShader(vertexShaderSource, fragmentShaderSource);
			r->SetShader(shader);

			visibleRenderers.push_back(r);
		}

		
	}

	

}
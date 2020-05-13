#include "CullResults.h"
#include "Shader.h"

namespace moon {

	std::vector<Renderer*> CullResults::visibleRenderers(0);

	float vertices[] = {
		// first triangle
		-0.9f, -0.5f, 0.0f,  // left 
		-0.0f, -0.5f, 0.0f,  // right
		-0.45f, 0.5f, 0.0f,  // top 
		// second triangle
		 0.0f, -0.5f, 0.0f,  // left
		 0.9f, -0.5f, 0.0f,  // right
		 0.45f, 0.5f, 0.0f   // top 
	};

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

	void CullResults::Cull(RendererContextI* context, Camera* camera)
	{
		//visibleRenderers.clear();


		if (visibleRenderers.size() == 0) {
			//test
			Renderer* r = new Renderer();


			Mesh* mesh = new Mesh();
			int indices[] = { 0, 1, 2 };
			mesh->SetIndices(indices, sizeof(indices));

			mesh->SetVertices(vertices, sizeof(vertices));
			r->SetMesh(mesh);

			Shader* shader = context->CreateShader();
			shader->CompileShader(vertexShaderSource, fragmentShaderSource);
			r->SetShader(shader);

			visibleRenderers.push_back(r);
		}

		
	}

	

}
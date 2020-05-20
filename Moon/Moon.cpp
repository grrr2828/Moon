#include <vector>

#include "AppI.h"
#include "Device.h"
#include "Shader.h"
#include "CullResults.h"

namespace moon {

	float vertices[] = {
		-0.9f, -0.5f, 0.0f,  // left 
		 0.0f, -0.5f, 0.0f,  // right
		-0.45f, 0.5f, 0.0f,  // top 
	};

	int indices[]{
		0,1,2
	};

	float uvs[] = {
		0.55f, 0.55f,
		0.55f, 0.45f,
		0.45f, 0.45f,
	};

	Color iColors[]{
		Color(1.0f, 0.0f, 0.0f),
		Color(0.0f, 1.0f, 0.0f),
		Color(0.0f, 0.0f, 1.0f),
	};

	Color ourColor(1.0f, 0.0f, 0.0f);

	float ourFloat = 1.0f;

	const char* vertexShaderSource = "#version 330 core\n"
		"layout (location = 0) in vec3 aPos;\n"
		"layout (location = 1) in vec3 aColor;\n"
		"out vec3 iColor;\n"
		"void main()\n"
		"{\n"
		"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
		"   iColor = aColor;\n"
		"}\0";
	const char* fragmentShaderSource = "#version 330 core\n"
		"out vec4 FragColor;\n"
		"in vec3 iColor;\n"
		"uniform vec4 ourColor;\n"
		"void main()\n"
		"{\n"
		"   FragColor = vec4(iColor.x, iColor.y, iColor.z, 1.0);;\n"
		"}\n\0";

	class Test : public AppI
	{
	public:

	
		Test()
			: AppI()
		{
			
		}

		void Start() override
		{
			//test
			Renderer* r = new Renderer();

			Mesh* mesh = new Mesh();
			mesh->SetIndices(indices, sizeof(indices));
			mesh->SetVertices(vertices, sizeof(vertices));
			mesh->SetColors(iColors, sizeof(iColors));
			mesh->SetUVs(uvs, sizeof(uvs));
			r->SetMesh(mesh);

			auto r_ctx = rendererProcessor->r_ctx;

			Shader* shader = r_ctx->CreateShader();
			shader->CompileShader(vertexShaderSource, fragmentShaderSource);
			r->SetShader(shader);

			shader->SetColor("ourColor", ourColor);
			shader->SetFloat("test", &ourFloat);

			CullResults::visibleRenderers.push_back(r);
		}

		bool Update() override
		{
			return AppI::Update();
		}

	};
}

int main(int argc, const char* const* argv)
{
	auto context = moon::s_ctx;
	context.AddApp( new moon::Test() );

	return context.run(argc, argv);
}

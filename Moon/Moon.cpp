#include <vector>

#include "AppI.h"
#include "Device.h"
#include "Shader.h"
#include "CullResults.h"
#include "FileUtils.h"
#include "Texture.h"

namespace moon {

	float vertices[] = {
		-0.9f, -0.5f, 0.0f,  
		 0.0f, -0.5f, 0.0f,  
		-0.45f, 0.5f, 0.0f, 

		 0.0f, -0.5f, 0.0f,
		 1.0f, -0.5f, 0.0f,
		 0.45f, 0.5f, 0.0f,
	};

	int indices0[]{
		0,1,2,
	};

	int indices1[]{
		3,4,5,
	};

	float uvs[] = {
		0.55f, 0.55f,
		0.55f, 0.45f,
		0.45f, 0.45f,
		0.55f, 0.55f,
		0.55f, 0.45f,
		0.45f, 0.45f,
	};

	Color iColors[]{
		Color(1.0f, 0.0f, 0.0f),
		Color(0.0f, 1.0f, 0.0f),
		Color(0.0f, 0.0f, 1.0f),
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

	Texture2D* texture;

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
			mesh->SetIndices(indices0, sizeof(indices0), 0);
			//mesh->SetIndices(indices1, sizeof(indices1), 1);

			mesh->SetVertices(vertices, sizeof(vertices));
			mesh->SetColors(iColors, sizeof(iColors));
			mesh->SetUVs(uvs, sizeof(uvs));


			r->SetMesh(mesh);

			auto r_ctx = rendererProcessor->r_ctx;

			Shader* shader = r_ctx->CreateShader();
			shader->CompileShader(vertexShaderSource, fragmentShaderSource);
			
			Material* material = new Material();
			material->SetShader(shader);
			r->SetMaterial(material);

			shader->SetColor("ourColor", ourColor);
			shader->SetFloat("test", &ourFloat);

			int w, h, channel;
			std::string imgPath = "E:\\Users\\Administrator\\source\\repos\\Moon\\resources\\textures\\test.jpg";
			unsigned char* imgData = FileUtils::LoadImage(imgPath.c_str(), &w, &h, &channel, 0);

			texture = new Texture2D();
			texture->Init(w, h, imgData);
			material->SetMainTexture(texture);

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

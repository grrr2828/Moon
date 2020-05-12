#include "CullResults.h"

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

	void CullResults::Cull(Camera* camera)
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

			visibleRenderers.push_back(r);
		}

		
	}

	

}
#include "CullResults.h"

namespace moon {

	std::vector<Renderer*> CullResults::visibleRenderers(100);


	void CullResults::Cull(Camera* camera)
	{
		visibleRenderers.clear();

		//test
		Renderer* r = new Renderer();

		Mesh* mesh = new Mesh();

		int indices[] = { 0, 1, 2 };
		mesh->SetIndices(indices, sizeof(indices));

		float vertices[] = { 0.5f, 0.5f, 0, 0.5f, -0.5f, 0, -0.5f, -0.5f, 0 };
		mesh->SetVertices(vertices, sizeof(vertices));

		r->SetMesh(mesh);

		visibleRenderers.push_back(r);
	}

	

}
#include "RendererProcessor.h"
#include "RendererGL.h"
#include "CullResults.h"

namespace moon {

	RendererProcessor::RendererProcessor()
	{
		r_ctx = new RendererContextGL();
		r_ctx->Init();



		currentPipeline = new RendererPipeline();

		//test
		Renderer* r = new Renderer();

		Mesh* mesh = new Mesh();

		int indices[] = { 0, 1, 2 };
		int size = sizeof(indices) / sizeof(indices[0]);
		mesh->SetIndices(indices, size);

		Vector vertices[] = { Vector(0.5f, 0.5f, 0), Vector(0.5f, -0.5f, 0), Vector(-0.5f, -0.5f, 0) };
		size = sizeof(vertices) / sizeof(vertices[0]);
		mesh->SetVertices(vertices, size);

		r->SetMesh( mesh );

		CullResults::AddRenderer(r);
		
	}

	RendererProcessor::~RendererProcessor()
	{
		if (r_ctx) {
			delete r_ctx;
			r_ctx = nullptr;
		}

		if (currentPipeline) {
			delete currentPipeline;
			currentPipeline = nullptr;
		}
	}



	void RendererProcessor::Run()
	{
		currentPipeline->Render(r_ctx, cameras);
	}


}
#include "CullResults.h"

namespace moon {

	std::vector<Renderer*> CullResults::visibleRenderers(100);


	void CullResults::Cull(Camera* camera)
	{
		visibleRenderers.clear();
	}

	void CullResults::AddRenderer(Renderer* renderer)
	{
		visibleRenderers.push_back(renderer);
	}

}
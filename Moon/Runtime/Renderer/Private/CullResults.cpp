#include "CullResults.h"

namespace moon {

	std::vector<Renderer*> CullResults::visibleRenderers;


	void CullResults::Cull(Camera* camera)
	{
		visibleRenderers.clear();
	}

}
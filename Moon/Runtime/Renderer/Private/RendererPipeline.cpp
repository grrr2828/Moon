#include "RendererPipeline.h"

namespace moon {

	
	RendererPipeline::RendererPipeline()
	{
	
	}

	RendererPipeline::~RendererPipeline()
	{
	
	}

	void RendererPipeline::AddRender(Renderer* render)
	{
		_renderList.push_back(render);
	}

	void RendererPipeline::RemoveRender(Renderer* render)
	{
		for (auto it = _renderList.begin(); it != _renderList.end(); it++) {
			if (*it == render) {
				it = _renderList.erase(it);
				if (it == _renderList.end()) {
					break;
				}
			}
		}
	}

	void RendererPipeline::Render()
	{
		int size = _renderList.size();

		for (size_t i = 0; i < size; i++)
		{
			auto render = _renderList[i];

		}
	}
	
}
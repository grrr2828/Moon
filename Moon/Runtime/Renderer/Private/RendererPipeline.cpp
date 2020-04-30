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

	void RendererPipeline::AddCommandPre(Command* cmd)
	{
		_cmdPre.Add( cmd );
	}

	void RendererPipeline::AddCommandPost(Command* cmd)
	{
		_cmdPost.Add( cmd );
	}

	void RendererPipeline::Render()
	{

		_cmdPre.Exce();



		_cmdPost.Exce();
	}
	
}
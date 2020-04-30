#pragma once

#include "RendererProcessor.h"

namespace moon {
	
	class AppI
	{
	public:
		AppI();

		virtual ~AppI();

		virtual bool Update();

		virtual void RenderFrame();

		RendererProcessor* rendererProcessor;
	private:


	};
}
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

		virtual void Start() {};

		RendererProcessor* rendererProcessor;
	private:


	};
}
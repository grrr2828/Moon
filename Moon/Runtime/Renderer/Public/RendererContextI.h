#pragma once

#include "GraphicsEnums.h"

namespace moon {

	struct RendererContextI
	{
		virtual RendererType GetRendererType() const = 0;

		void RenderFrame() {};
	};

}
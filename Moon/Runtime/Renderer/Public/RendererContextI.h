#pragma once

#include "GraphicsEnums.h"
#include "Color.h"

namespace moon {

	struct RendererContextI
	{
		virtual RendererType GetRendererType() const { return RendererType::Count; };

		virtual void BufferClear(const Color& color) {};
	};

}
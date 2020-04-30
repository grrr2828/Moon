#pragma once

#include "GraphicsEnums.h"

namespace moon {

	struct RendererContextI
	{
		virtual RendererType GetRendererType() const { return RendererType::Count; };

		virtual void BufferClear() {};
	};

}
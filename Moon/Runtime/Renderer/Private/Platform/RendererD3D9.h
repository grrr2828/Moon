#pragma once

#include "RendererContextI.h"

namespace moon {

	class RendererD3D9 : public RendererContextI
	{
	public:

		RendererType GetRendererType() const override;
	};

}

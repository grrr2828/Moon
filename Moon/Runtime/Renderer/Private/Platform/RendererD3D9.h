#pragma once

#include "RendererContextI.h"

namespace moon {

	struct RendererD3D9 : public RendererContextI
	{
		RendererType GetRendererType() const override;
	};

}

#pragma once

#include "RendererContextI.h"

namespace moon {

	struct RendererContextGL : public RendererContextI
	{
		
		RendererContextGL();

		~RendererContextGL();

		RendererType GetRendererType() const override;

		void BufferClear() override;
	};

}

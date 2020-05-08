#pragma once

#include "RendererContextI.h"

namespace moon {

	class RendererContextGL : public RendererContextI
	{

	public:
		
		RendererContextGL();

		~RendererContextGL();

		RendererType GetRendererType() const override;

		void BufferClear(const Color& color) override;
	};

}

#pragma once

#include "RendererPipeline.h"

namespace moon {

	class RendererProcessor
	{
	public:
		RendererProcessor();
		~RendererProcessor();

		void AddPipeline(RendererPipeline* pipeline);

		void Run();

	private:

	};
}
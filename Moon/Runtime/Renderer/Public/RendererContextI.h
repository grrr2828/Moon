#pragma once

#include <vector>

#include "GraphicsEnums.h"
#include "Color.h"

namespace moon {

	class RendererCommand;

	class Buffer
	{
	public:
		Buffer() {};
		~Buffer() {};

		void* data = nullptr;
	private:

	};

	class RendererContextI
	{

	public:

		virtual void Init() {};
		
		virtual RendererType GetRendererType() const { return RendererType::Count; };

		virtual void ClearTarget(const Color& color) {};

		virtual Buffer* CreateBuffer() { return nullptr; };
		virtual void ReleaseBuffer(Buffer* buffer) {};

		virtual void Submit();
		void AddCommand(RendererCommand* cmd);

	private:

		std::vector<RendererCommand*> renderQueue;
		
	};

}
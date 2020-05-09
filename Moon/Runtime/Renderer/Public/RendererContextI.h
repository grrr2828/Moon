#pragma once

#include <vector>

#include "GraphicsEnums.h"
#include "Color.h"
#include "Renderer.h"

namespace moon {

	class Buffer
	{
	public:
		Buffer() {};
		~Buffer() {};

		void* indices = nullptr;
		void* vertices = nullptr;
	private:

	};

	class RendererContextI
	{

	public:

		virtual void Init() {};
		
		virtual RendererType GetRendererType() const { return RendererType::Count; };

		virtual void ClearTarget(const Color& color) {};

		virtual void DrawRenderers(std::vector<Renderer*> &renderers);

		virtual void Submit();

		void AddCommand(RendererCommand* cmd);

		virtual Buffer* CreateBuffer() { return nullptr; };
		virtual void ReleaseBuffer(Buffer* buffer) {};
	public:
		std::vector<RendererCommand*> renderQueue;

		

	};

}
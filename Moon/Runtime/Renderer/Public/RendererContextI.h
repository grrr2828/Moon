#pragma once

#include <vector>

#include "GraphicsEnums.h"
#include "Color.h"

namespace moon {

	class RendererCommand;
	class Shader;

	class Buffer
	{
	public:
		Buffer() {};
		~Buffer() {};

		virtual void Refresh() {};
		
		virtual void UpdateData(void* data, std::size_t size) {};
	private:

	};

	

	class RendererContextI
	{

	public:

		virtual void Init() {};
		
		virtual RendererType GetRendererType() const { return RendererType::Count; };

		virtual void ClearTarget(const Color& color) {};

		virtual Buffer* CreateBuffer() { return nullptr; };

		virtual Shader* CreateShader() { return nullptr; };

		virtual void Draw(Buffer* verts, Buffer* indices, Shader* shader) {};

		virtual void Submit();
		void AddCommand(RendererCommand* cmd);

	private:

		std::vector<RendererCommand*> renderQueue;
		
	};

}
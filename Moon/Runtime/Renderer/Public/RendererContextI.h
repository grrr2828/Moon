#pragma once

#include <vector>

#include "GraphicsEnums.h"
#include "Color.h"

namespace moon {

	class RendererCommand;
	class Shader;


	class RendererContextI
	{

	public:

		virtual void Init() {};
		
		virtual RendererType GetRendererType() const { return RendererType::Count; };

		virtual void ClearTarget(const Color& color) {};

		virtual Shader* CreateShader() { return nullptr; };

		virtual RendererCommand* CreateRendererCommand() { return nullptr; };


		virtual void Submit();
		void AddCommand(RendererCommand* cmd);

	private:

		std::vector<RendererCommand*> renderQueue;
		
	};

}
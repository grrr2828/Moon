#pragma once

#include <vector>

#include "GraphicsEnums.h"
#include "Color.h"
#include "Texture.h"

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

		virtual Texture2D* CreateTexture2D() { return nullptr; };
		
	};

}
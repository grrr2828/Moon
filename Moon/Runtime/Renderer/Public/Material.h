#pragma once

#include "Shader.h"
#include "Texture.h"

namespace moon {

	class Material
	{
	public:
	
		Material();
		~Material();

		void SetShader(Shader* shader);

		Shader* GetShader()
		{
			return _shader;
		}

		void SetMainTexture(Texture2D* texture)
		{
			_shader->SetMainTexture(texture);
		}

	private:


		Shader* _shader;
	};

}
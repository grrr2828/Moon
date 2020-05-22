#pragma once

#include "Shader.h"
#include "Texture2D.h"

namespace moon {

	class Material
	{
	public:
		Material();
		~Material();

		void SetShader(Shader* shader);

		Texture2D* mainTexture;
	private:


		Shader* _shader;
	};

}
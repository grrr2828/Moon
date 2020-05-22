#include "Material.h"

namespace moon {

	
	Material::Material()
	{
	
	}

	Material::~Material()
	{
	
	}

	void Material::SetShader(Shader* shader)
	{
		_shader = shader;
	}

}
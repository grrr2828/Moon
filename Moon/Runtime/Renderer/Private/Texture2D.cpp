#include "Texture2D.h"

namespace moon {

	
	Texture2D::Texture2D(int width, int height, unsigned char* data)
	{
		_width = width;
		_height = height;

		_data = data;
	}

	Texture2D::~Texture2D()
	{
		_data = nullptr;
	}


}
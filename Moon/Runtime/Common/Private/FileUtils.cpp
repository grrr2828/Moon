#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"


#include "FileUtils.h"


namespace moon {


	unsigned char* FileUtils::LoadImage(char const* filename, int* x, int* y, int* channels_in_file, int desired_channels)
	{
		return stbi_load(filename, x, y, channels_in_file, desired_channels);
	}
	
}
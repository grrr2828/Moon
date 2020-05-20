#pragma once


namespace moon {

	
	class FileUtils
	{
	public:
		static unsigned char* LoadImage(char const* filename, int* x, int* y, int* channels_in_file, int desired_channels);
	private:

	};

	

}
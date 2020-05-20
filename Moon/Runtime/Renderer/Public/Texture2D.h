#pragma once

namespace moon {

	class Texture2D
	{
	public:
		 Texture2D(int width, int height, unsigned char* data);
		~Texture2D();

		virtual void Init() {};
	protected:

		int _width;
		int _height;

		unsigned char* _data;
	};

}
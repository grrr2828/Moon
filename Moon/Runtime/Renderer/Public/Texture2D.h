#pragma once

namespace moon {

	class Texture2D
	{
	public:
		 Texture2D();
		~Texture2D();

		virtual void Init(int width, int height, unsigned char* data);
	protected:

		int _width;
		int _height;

		unsigned char* _data;
	};

}
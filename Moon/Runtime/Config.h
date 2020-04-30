#pragma once
#include <stdint.h> // uint32_t

#include "GraphicsEnums.h"

namespace moon {

	struct PlatformData
	{
		PlatformData() {};

		void* ndt;         
		void* nwh;         
							
		void* context;      
		void* backBuffer;   
							
		void* backBufferDS; 
							
	};


	struct Config
	{
		Config() {};

		RendererType type;

		uint16_t deviceId;

		bool debug;   
		bool profile; 

		PlatformData platformData;

	};
}

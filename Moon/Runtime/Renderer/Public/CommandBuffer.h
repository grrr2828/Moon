#pragma once

#include <vector>

#include "Command.h"

namespace moon {

	
	class CommandBuffer
	{
	public:

		CommandBuffer();

		~CommandBuffer();

		void Add(Command* cmd);

		void Clear();

		void Exce();

	private:

		std::vector<Command*> buffer;
	};

	
}
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

		void Submit();

	private:

		std::vector<Command*> buffer;
	};

	
}
#include "CommandBuffer.h"

namespace moon {

	CommandBuffer::CommandBuffer()
	{

	}

	CommandBuffer::~CommandBuffer()
	{
		Clear();
	}

	void CommandBuffer::Exce()
	{
		int size = buffer.size();

		for (int i = 0; i < size; i++)
		{
			auto cmd = buffer[i];
			cmd->ExecuteCommand();
		}
	}

	void CommandBuffer::Add(Command* cmd)
	{
		buffer.push_back(cmd);
	}

	void CommandBuffer::Clear()
	{
		int size = buffer.size();

		for (int i = 0; i < size; i++)
		{
			auto cmd = buffer[i];
			if (cmd) {
				delete cmd;
				cmd = nullptr;
			}
		}

		buffer.clear();

	}

}
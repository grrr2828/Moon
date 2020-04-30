#pragma once

#include <vector>

namespace moon {

	class Command
	{

	public:

		enum CommandEnum
		{
			RendererInit,
		};


		virtual void ExecuteCommand() = 0;

	};

	class CommandBuffer
	{
	public:

		CommandBuffer();

		~CommandBuffer();

		void Add(Command* cmd);

		void Clear();

	private:

		std::vector<Command*> buffer;
	};
}
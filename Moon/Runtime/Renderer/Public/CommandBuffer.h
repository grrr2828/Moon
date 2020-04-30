#pragma once

#include <vector>

namespace moon {

	class Command
	{

	public:

		enum CommandEnum
		{
			RendererInit,
			RendererBufferClear,
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

		void Exce();

	private:

		std::vector<Command*> buffer;
	};
}
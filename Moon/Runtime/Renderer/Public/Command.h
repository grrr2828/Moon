#pragma once

#include <vector>
#include "Color.h"

namespace moon {

	class RendererContextI;

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


	class RendererCommand : public Command
	{
	public:

		RendererCommand();
		~RendererCommand();

		void ExecuteCommand() override;


		RendererContextI* context = nullptr;

		std::vector<int>* indices = nullptr;
		std::vector<Vector>* vertices = nullptr;

	};


	class BufferClearCommand : public RendererCommand
	{
	public:

		void ExecuteCommand() override;

		Color color;

	};

	class VertexBufferCommand : public RendererCommand
	{
	public:
		void ExecuteCommand() override;

	};

	
}
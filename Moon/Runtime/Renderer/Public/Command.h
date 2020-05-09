#pragma once

#include <vector>
#include "Color.h"


namespace moon {

	class RendererContextI;
	class Buffer;
	class Mesh;

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

		void PrepareDraw(RendererContextI* context, Mesh* mesh);

		void ExecuteCommand() override;

		Buffer* indices = nullptr;
		Buffer* vertices = nullptr;

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
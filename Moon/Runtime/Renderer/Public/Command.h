#pragma once

#include <vector>

#include "RendererContextI.h"
#include "Color.h"

namespace moon {

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

		void PrepareDraw(RendererContextI* context, Mesh* mesh, Shader* shader);

		void ExecuteCommand() override;

		Buffer* indicesBuffer = nullptr;
		Buffer* verticesBuffer = nullptr;

		Shader* _shader = nullptr;

	private:

		RendererContextI* _context;

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
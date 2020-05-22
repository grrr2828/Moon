#pragma once

#include <vector>

#include "RendererContextI.h"
#include "Color.h"

namespace moon {

	class Mesh;
	class Buffer;
	class VertexLayout;

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

		virtual void Init(Mesh* mesh, Buffer* indices, int subMeshOffSet, Shader* shader);

		void ExecuteCommand() override;

		Shader* _shader = nullptr;

	private:
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
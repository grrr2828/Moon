#pragma once

#include <vector>

#include "RendererContextI.h"
#include "Color.h"
#include "Material.h"

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

		virtual void Init(Mesh* mesh, const std::vector<Material*>& materials);

		void ExecuteCommand() override;
	protected:
		std::vector<Material*> _materials;
		Mesh* _mesh = nullptr;
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
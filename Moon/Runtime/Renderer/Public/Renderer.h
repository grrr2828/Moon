#pragma once

#include "Mesh.h"
#include "CommandBuffer.h"
#include "RendererContextI.h"

namespace moon {


	class  RendererCommand : public Command
	{
	public:
		
		void ExecuteCommand() override;


		RendererContextI* r_ctx;
	private:

	};


	class BufferClearCommand : public RendererCommand
	{
	public:
		
		void ExecuteCommand() override;

		Color color;
	private:

	};

	

	class Renderer
	{
	public:
		Renderer();
		~Renderer();

	private:

		Mesh* _mesh;

		RendererCommand* _command;

	};

}
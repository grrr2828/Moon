#pragma once


namespace moon {

	class Thread
	{
	public:

		void Init();

		void Run();

		virtual ~Thread() { }
	};

}
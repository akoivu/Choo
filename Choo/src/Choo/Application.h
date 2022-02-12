#pragma once

#include "Core.h"

namespace Choo {
	class CHOO_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// Define in client
	Application* CreateApplication();
}



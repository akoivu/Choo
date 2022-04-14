#pragma once

#include "Core.h"
#include "Events/Event.h"

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



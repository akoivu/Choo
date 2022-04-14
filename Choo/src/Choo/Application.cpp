#include "Application.h"

#include "Choo/Events/ApplicationEvent.h"
#include "Choo/Log.h"
namespace Choo {

	Application::Application() {

	}

	Application::~Application() {

	}

	void Application::Run() {
		WindowResizeEvent e(1280, 720);
		CHOO_TRACE(e);

		while (true);
	}
}
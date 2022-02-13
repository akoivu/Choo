#pragma once

#ifdef CHOO_PLATFORM_WINDOWS

extern Choo::Application* Choo::CreateApplication();

int main(int argc, char** argv) {
	Choo::Log::Init();
	CHOO_CORE_WARNING("Log init done");
	CHOO_INFO("HELLO");


	auto app = Choo::CreateApplication();
	app->Run();
	delete app;
}

#endif // CHOO_PLATFORM_WINDOWS


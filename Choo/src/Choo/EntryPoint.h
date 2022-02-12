#pragma once

#ifdef CHOO_PLATFORM_WINDOWS

extern Choo::Application* Choo::CreateApplication();

int main(int argc, char** argv) {
	auto app = Choo::CreateApplication();
	app->Run();
	delete app;
}

#endif // CHOO_PLATFORM_WINDOWS


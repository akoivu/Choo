
#include <Choo.h>

class Sandbox : public Choo::Application {

public:
	Sandbox() {

	}

	~Sandbox() {

	}
};

Choo::Application* Choo::CreateApplication() {
	return new Sandbox();
}
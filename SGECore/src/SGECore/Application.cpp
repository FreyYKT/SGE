#include "SGECore/Application.hpp"
#include "SGECore/Log.hpp"
#include "SGECore/Window.hpp"

namespace SGE {
	Application::Application() {
        LOG_INFO("Starting Application...");
	}
	Application::~Application() {
		LOG_INFO("Closing Application...");
	}

	int Application::start(unsigned int window_width, unsigned int window_height, const char* title) {
		window = std::make_unique<Window>(title, window_width, window_height);

		while (true) {
			window->on_update();
			on_update();
		}

        return 0;
	}
}
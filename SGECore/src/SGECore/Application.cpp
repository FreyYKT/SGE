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

		eventDispatcher.addEventListener<EventMouseMoved>(
			[](EventMouseMoved& event) {
				LOG_INFO("[MouseMoved] Mouse moved to {0}x{1}", event.x, event.y);
			}
		);

		eventDispatcher.addEventListener<EventWindowResize>(
			[](EventWindowResize& event) {
				LOG_INFO("[EVENT] Changed window size to {0}x{1}", event.width, event.height);
			}
		);

		eventDispatcher.addEventListener<EventWindowClose>(
			[&](EventWindowClose& event) {
				LOG_INFO("[WindowClosed]");
				isWindowClosed = true;
			}
		);

		window->setEventCallback(
			[&](BaseEvent& event) {
				eventDispatcher.dispatch(event);
			}
		);

		while (!isWindowClosed) {
			window->on_update();
			on_update();
		}

		window = nullptr;

        return 0;
	}
}
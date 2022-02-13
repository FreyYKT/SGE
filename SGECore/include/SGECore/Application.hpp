#pragma once

#include <memory>

namespace SGE{

	class Application {
	public:
		Application();
		virtual ~Application();

		Application(const Application&) = delete;
		Application(const Application&&) = delete;
		Application& operator=(const Application&) = delete;
		Application& operator=(const Application&&) = delete;

		virtual int start(unsigned int window_width, unsigned int window_height, const char* title);
		virtual void on_update() {};

	private:
		std::unique_ptr<class Window> window;

	};

}
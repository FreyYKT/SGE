#pragma once

#include "SGECore/Event.hpp"

#include <string>
#include <functional>

struct GLFWwindow;

namespace SGE {

	class Window {
	public:
		using EventCallbackFn = std::function<void(BaseEvent&)>;

		Window(std::string title, const unsigned int width, const unsigned int height);
		~Window();

		Window(const Window&) = delete;
		Window(const Window&&) = delete;
		Window& operator=(const Window&) = delete;
		Window& operator=(const Window&&) = delete;

		void on_update();
		unsigned int getWidth() const { return data.width; };
		unsigned int getHeight() const { return data.height; };

		void setEventCallback(const EventCallbackFn& callback) {
			data.eventCallbackFn = callback;
		}

	private:
		struct WindowData {
			std::string title;
			unsigned int width;
			unsigned int height;
			EventCallbackFn eventCallbackFn;
		};

		GLFWwindow* window = nullptr;
		WindowData data;

		int init();
		void shutdown();
	};
}
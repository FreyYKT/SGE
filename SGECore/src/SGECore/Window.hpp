#pragma once
#include <string>

struct GLFWwindow;

namespace SGE {

	class Window {
	public:
		Window(std::string title, const unsigned int width, const unsigned int height);
		~Window();

		Window(const Window&) = delete;
		Window(const Window&&) = delete;
		Window& operator=(const Window&) = delete;
		Window& operator=(const Window&&) = delete;

		void on_update();
		unsigned int getWidth() const { return width; };
		unsigned int getHeight() const { return height; };

	private:
		int init();
		void shutdown();

		GLFWwindow* window;
		std::string title;
		unsigned int width;
		unsigned int height;

	};

}
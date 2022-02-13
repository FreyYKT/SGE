#include "SGECore/Window.hpp"
#include "SGECore/Log.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace SGE {
    static bool s_GLFW_initialized = false;

	Window::Window(std::string title, const unsigned int width, const unsigned int height)
		: title(std::move(title)), width(width), height(height)
	{
		int res_code = init();
	}
	Window::~Window() {
		shutdown();
	}

	int Window::init() {
        LOG_INFO("Create window {0} sized {1}x{2}", title, width, height);

        if (!s_GLFW_initialized) {
            if (!glfwInit()) {
                LOG_CRITICAL("Can't initialize GLFW!");
                return -1;
            }
            s_GLFW_initialized = true;
        }

        window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
        if (!window)
        {
            LOG_CRITICAL("Can't create window {0} sized {1}x{2}!", title, width, height);
            glfwTerminate();
            return -2;
        }

        glfwMakeContextCurrent(window);

        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            LOG_CRITICAL("Failed to initialize GLAD");
            return -3;
        }
	}

	void Window::shutdown() {
        glfwDestroyWindow(window);
        glfwTerminate();
	}

	void Window::on_update() {
        glClearColor(0.5, 0.5, 0.5, 1);
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
        glfwPollEvents();    
    }
}
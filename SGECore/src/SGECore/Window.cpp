#include "SGECore/Window.hpp"
#include "SGECore/Log.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace SGE {
    static bool s_GLFW_initialized = false;

	Window::Window(std::string title, const unsigned int width, const unsigned int height)
        : data({ std::move(title), width, height })
	{
		int res_code = init();
	}
	Window::~Window() {
		shutdown();
	}

	int Window::init() {
        LOG_INFO("Create window {0} sized {1}x{2}", data.title, data.width, data.height);

        if (!s_GLFW_initialized) {
            if (!glfwInit()) {
                LOG_CRITICAL("Can't initialize GLFW!");
                return -1;
            }
            s_GLFW_initialized = true;
        }

        window = glfwCreateWindow(data.width, data.height, data.title.c_str(), nullptr, nullptr);
        if (!window)
        {
            LOG_CRITICAL("Can't create window {0} sized {1}x{2}!", data.title, data.width, data.height);
            glfwTerminate();
            return -2;
        }

        glfwMakeContextCurrent(window);

        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            LOG_CRITICAL("Failed to initialize GLAD");
            return -3;
        }

        glfwSetWindowUserPointer(window, &data);

        glfwSetWindowSizeCallback(window,
            [](GLFWwindow* window, int width, int height) {
                WindowData& data = *static_cast<WindowData*>(glfwGetWindowUserPointer(window));
                data.width = width;
                data.height = height;

                EventWindowResize event(width, height);
                data.eventCallbackFn(event);
            }
        );

        glfwSetCursorPosCallback(window,
            [](GLFWwindow* pWindow, double x, double y)
            {
                WindowData& data = *static_cast<WindowData*>(glfwGetWindowUserPointer(pWindow));

                EventMouseMoved event(x, y);
                data.eventCallbackFn(event);
            }
        );

        glfwSetWindowCloseCallback(window,
            [](GLFWwindow* pWindow)
            {
                WindowData& data = *static_cast<WindowData*>(glfwGetWindowUserPointer(pWindow));

                EventWindowClose event;
                data.eventCallbackFn(event);
            }
        );
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
cmake_minimum_required(VERSION 3.21 FATAL_ERROR)

set(PROJECT_NAME SGECore)

set(PROJECT_PUBLIC_INCLUDES
	include/SGECore/Application.hpp
	include/SGECore/Log.hpp
	include/SGECore/Event.hpp
)

set(PROJECT_PRIVATE_INCLUDES
	src/SGECore/Window.hpp
)

set(PROJECT_PRIVATE_SOURCES
	src/SGECore/Application.cpp
	src/SGECore/Window.cpp
)

add_library(${PROJECT_NAME} STATIC
	${PROJECT_PUBLIC_INCLUDES}
	${PROJECT_PRIVATE_INCLUDES}
	${PROJECT_PRIVATE_SOURCES}
)

target_include_directories(${PROJECT_NAME} PUBLIC include)
target_include_directories(${PROJECT_NAME} PRIVATE src)
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)

add_subdirectory(../external/glfw ${CMAKE_CURRENT_BINARY_DIR}/glfw)
target_link_libraries(${PROJECT_NAME} PRIVATE glfw)

add_subdirectory(../external/spdlog ${CMAKE_CURRENT_BINARY_DIR}/spdlog)
target_link_libraries(${PROJECT_NAME} PRIVATE spdlog)

add_subdirectory(../external/glad ${CMAKE_CURRENT_BINARY_DIR}/glad)
target_link_libraries(${PROJECT_NAME} PRIVATE glad)

#
# ImGui
#

set(IMGUI_INCLUDE
	../external/imgui/imgui.h
	../external/imgui/backends/imgui_impl_glfw.h
	../external/imgui/backends/imgui_impl_opengl3.h
)

set(IMGUI_SOURCE
	../external/imgui/imgui.cpp
	../external/imgui/backends/imgui_impl_glfw.cpp
	../external/imgui/backends/imgui_impl_opengl3.cpp
	../external/imgui/imgui_draw.cpp	
	../external/imgui/imgui_demo.cpp
	../external/imgui/imgui_tables.cpp
	../external/imgui/imgui_widgets.cpp
)

add_library(ImGui STATIC
	${IMGUI_INCLUDE}
	${IMGUI_SOURCE}
)

target_include_directories(ImGui PUBLIC ../external)
target_include_directories(ImGui PUBLIC ../external/imgui)
target_link_libraries(ImGui PRIVATE glad glfw)

target_link_libraries(${PROJECT_NAME} PRIVATE ImGui)
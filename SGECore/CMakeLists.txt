cmake_minimum_required(VERSION 3.21 FATAL_ERROR)

set(PROJECT_NAME SGECore)

set(PROJECT_PUBLIC_INCLUDES
	include/SGECore/Application.hpp
)

set(PROJECT_PRIVATE_INCLUDES
	src/SGECore/Application.cpp
)

add_library(${PROJECT_NAME} STATIC
	${PROJECT_PUBLIC_INCLUDES}
	${PROJECT_PRIVATE_INCLUDES}
)

target_include_directories(${PROJECT_NAME} PUBLIC include)
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)

add_subdirectory(../external/glfw ${CMAKE_CURRENT_BINARY_DIR}/glfw)
target_link_libraries(${PROJECT_NAME} PRIVATE glfw)

add_subdirectory(../external/spdlog ${CMAKE_CURRENT_BINARY_DIR}/spdlog)
target_link_libraries(${PROJECT_NAME} PRIVATE spdlog)
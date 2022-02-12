cmake_minimum_required(VERSION 3.21 FATAL_ERROR)

set(PROJECT_NAME SGEEditor)

project(${PROJECT_NAME})

add_executable(${PROJECT_NAME}
	src/main.cpp
)

target_link_libraries(${PROJECT_NAME} SGECore)
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)

set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/)
cmake_minimum_required(VERSION 3.21 FATAL_ERROR)

set(PROJECT_NAME SGECore)

add_library(${PROJECT_NAME} STATIC
	src/SGECore/Utils/test.cpp
	include/SGECore/Utils/test.hpp
)

target_include_directories(${PROJECT_NAME} PUBLIC include)
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)
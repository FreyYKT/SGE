cmake_minimum_required(VERSION 3.21 FATAL_ERROR)

set(PROJECT_NAME SGE)

project(${PROJECT_NAME})

add_subdirectory(SGECore)
add_subdirectory(SGEEditor)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT SGEEditor)
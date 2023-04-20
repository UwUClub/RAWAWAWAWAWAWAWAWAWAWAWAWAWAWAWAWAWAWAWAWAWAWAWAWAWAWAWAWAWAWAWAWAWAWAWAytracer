cmake_minimum_required(VERSION 3.13)  # CMake version check

target_include_directories(color PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")

add_subdirectory(Camera)
add_subdirectory(Light)
add_subdirectory(Primitives)
add_subdirectory(Color)

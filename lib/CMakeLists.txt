cmake_minimum_required(VERSION 3.13)  # CMake version check

target_include_directories(raytracer PRIVATE "../plugins")

add_subdirectory(Camera)
add_subdirectory(Light)
add_subdirectory(Primitives)

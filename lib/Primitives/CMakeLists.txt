cmake_minimum_required(VERSION 3.13)  # CMake version check

target_include_directories(plane PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(sphere PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")

add_subdirectory(Plane)
add_subdirectory(Sphere)
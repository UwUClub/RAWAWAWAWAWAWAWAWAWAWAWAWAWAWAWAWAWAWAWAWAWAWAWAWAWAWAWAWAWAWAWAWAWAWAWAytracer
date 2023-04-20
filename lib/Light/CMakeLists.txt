cmake_minimum_required(VERSION 3.13)  # CMake version check

target_include_directories(directionalLight PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(pointLight PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")

add_subdirectory(DirectionalLight)
add_subdirectory(PointLight)

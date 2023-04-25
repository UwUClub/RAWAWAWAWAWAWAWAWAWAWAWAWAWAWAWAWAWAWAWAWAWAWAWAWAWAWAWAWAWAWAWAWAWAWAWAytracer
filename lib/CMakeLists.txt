cmake_minimum_required(VERSION 3.13)  # CMake version check

target_include_directories(color PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(color PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(camera PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(directionalLight PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(pointLight PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(plane PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(sphere PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")

add_subdirectory(Camera)
add_subdirectory(Light)
add_subdirectory(Primitives)
add_subdirectory(Color)

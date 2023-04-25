cmake_minimum_required(VERSION 3.13)  # CMake version check

target_include_directories(plane PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(plane PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(cylinder PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(cone PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")


add_subdirectory(Plane)
add_subdirectory(Plane)
add_subdirectory(Cylinder)
add_subdirectory(Cone)

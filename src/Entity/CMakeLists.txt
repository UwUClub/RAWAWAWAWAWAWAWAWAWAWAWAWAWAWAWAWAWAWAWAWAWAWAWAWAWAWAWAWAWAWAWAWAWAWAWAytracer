cmake_minimum_required(VERSION 3.13)  # CMake version check

target_include_directories(raytracer PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")

include_directories(../Utils)

target_sources(raytracer PRIVATE
		"${CMAKE_CURRENT_SOURCE_DIR}/Entity.cpp"
		)

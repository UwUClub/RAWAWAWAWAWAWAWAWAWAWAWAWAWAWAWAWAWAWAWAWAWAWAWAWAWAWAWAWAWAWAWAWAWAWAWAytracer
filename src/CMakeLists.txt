cmake_minimum_required(VERSION 3.13)  # CMake version check

target_include_directories(raytracer PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(color PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")

target_sources(raytracer PRIVATE
		"${CMAKE_CURRENT_SOURCE_DIR}/Main.cpp"
		)

add_subdirectory(ColorPlugin)
add_subdirectory(Entity)
add_subdirectory(Parser)
add_subdirectory(Plugin)
add_subdirectory(Scene)
add_subdirectory(Utils)

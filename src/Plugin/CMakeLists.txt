cmake_minimum_required(VERSION 3.13)  # CMake version check

target_include_directories(raytracer PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(unit_tests PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")

target_sources(raytracer PRIVATE
		"${CMAKE_CURRENT_SOURCE_DIR}/Plugin.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/PluginManager.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/PluginObserver.cpp"
		)

target_sources(unit_tests PRIVATE
		"${CMAKE_CURRENT_SOURCE_DIR}/Plugin.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/PluginManager.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/PluginObserver.cpp"
		)

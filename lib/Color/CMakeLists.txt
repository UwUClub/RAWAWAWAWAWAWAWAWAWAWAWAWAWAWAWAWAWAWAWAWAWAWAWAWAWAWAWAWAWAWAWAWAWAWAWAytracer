cmake_minimum_required(VERSION 3.13)  # CMake version check

target_include_directories(color PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")

target_sources(color PRIVATE
		"${CMAKE_CURRENT_SOURCE_DIR}/Color.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Api.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/../../src/Entity/Entity.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/../../src/Utils/Point.cpp"
		)

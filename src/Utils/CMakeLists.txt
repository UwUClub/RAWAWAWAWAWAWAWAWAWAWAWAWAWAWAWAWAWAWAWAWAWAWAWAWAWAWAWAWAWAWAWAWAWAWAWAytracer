cmake_minimum_required(VERSION 3.13)  # CMake version check

target_include_directories(raytracer PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(camera PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(directionalLight PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(pointLight PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(plane PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(sphere PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")

target_sources(raytracer PRIVATE
		"${CMAKE_CURRENT_SOURCE_DIR}/Vector.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Point.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Euler.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Color.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Pixel.cpp"
		)

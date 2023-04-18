cmake_minimum_required(VERSION 3.13)  # CMake version check

target_include_directories(raytracer PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")

target_sources(raytracer PRIVATE
		"${CMAKE_CURRENT_SOURCE_DIR}/CameraParser.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Parser.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/PlaneParser.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/PointLightParser.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/SphereParser.cpp"
		)

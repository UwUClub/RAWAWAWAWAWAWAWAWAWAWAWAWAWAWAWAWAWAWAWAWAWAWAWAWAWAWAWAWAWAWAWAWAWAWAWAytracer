cmake_minimum_required(VERSION 3.13)  # CMake version check

target_include_directories(raytracer PRIVATE ".")

target_sources(raytracer PRIVATE
		"${CMAKE_CURRENT_SOURCE_DIR}/Light.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/PointLight.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/DirectionalLight.cpp"
		)

cmake_minimum_required(VERSION 3.13)  # CMake version check

target_include_directories(pointLight PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")

target_sources(pointLight PRIVATE
		"${CMAKE_CURRENT_SOURCE_DIR}/Api.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/PointLight.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/../../../src/Entity/Entity.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/../../../src/Utils/Point.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/../../../src/Utils/Vector.cpp"
		)

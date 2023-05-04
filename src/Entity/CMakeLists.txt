cmake_minimum_required(VERSION 3.13)  # CMake version check

target_include_directories(raytracer PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(camera PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(directionalLight PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(pointLight PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(basicLight PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(plane PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(sphere PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(cylinder PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(cone PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(unit_tests PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")

target_sources(raytracer PRIVATE
		"${CMAKE_CURRENT_SOURCE_DIR}/Entity.cpp"
		)

target_sources(unit_tests PRIVATE
		"${CMAKE_CURRENT_SOURCE_DIR}/Entity.cpp"
		)

cmake_minimum_required(VERSION 3.13)  # CMake version check

target_include_directories(raytracer PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")

target_link_libraries(${PROJECT_NAME} ${CMAKE_DL_LIBS} config++)

target_sources(raytracer PRIVATE
		"${CMAKE_CURRENT_SOURCE_DIR}/CameraParser.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Parser.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/PrimitivesParser.cpp"
		)

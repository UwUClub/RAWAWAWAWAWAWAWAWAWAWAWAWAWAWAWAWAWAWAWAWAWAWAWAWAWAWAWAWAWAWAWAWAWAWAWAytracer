cmake_minimum_required(VERSION 3.13)  # CMake version check
set(PROJECT_NAME raytracer)
project(${PROJECT_NAME})            # Create project "simple_example"
set(CMAKE_CXX_STANDARD 20)            # Enable c++14 standard
set(EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic")
set(CMAKE_CXX_FLAGS_DEBUG "-lcriterion")

add_executable(${PROJECT_NAME})

set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 20
    COMPILE_FLAGS ""
    RUNTIME_OUTPUT_DIRECTORY "../"
)

target_link_libraries(${PROJECT_NAME} ${CMAKE_DL_LIBS} config++)

add_library(plane SHARED)
set_target_properties(plane PROPERTIES
		CXX_STANDARD 20
		COMPILE_FLAGS "-fno-gnu-unique"
		LIBRARY_OUTPUT_DIRECTORY "../plugins"
		)

add_library(sphere SHARED)
set_target_properties(sphere PROPERTIES
		CXX_STANDARD 20
		COMPILE_FLAGS "-fno-gnu-unique"
		LIBRARY_OUTPUT_DIRECTORY "../plugins"
		)

add_library(cone SHARED)
set_target_properties(cone PROPERTIES
		CXX_STANDARD 20
		COMPILE_FLAGS "-fno-gnu-unique"
		LIBRARY_OUTPUT_DIRECTORY "../plugins"
		)

add_library(cylinder SHARED)
set_target_properties(cylinder PROPERTIES
		CXX_STANDARD 20
		COMPILE_FLAGS "-fno-gnu-unique"
		LIBRARY_OUTPUT_DIRECTORY "../plugins"
		)

add_library(camera SHARED)
set_target_properties(camera PROPERTIES
		CXX_STANDARD 20
		COMPILE_FLAGS "-fno-gnu-unique"
		LIBRARY_OUTPUT_DIRECTORY "../plugins"
		)

add_library(pointLight SHARED)
set_target_properties(pointLight PROPERTIES
		CXX_STANDARD 20
		COMPILE_FLAGS "-fno-gnu-unique"
		LIBRARY_OUTPUT_DIRECTORY "../plugins"
		)

add_library(directionalLight SHARED)
set_target_properties(directionalLight PROPERTIES
		CXX_STANDARD 20
		COMPILE_FLAGS "-fno-gnu-unique"
		LIBRARY_OUTPUT_DIRECTORY "../plugins"
		)

add_library(basicLight SHARED)
set_target_properties(basicLight PROPERTIES
		CXX_STANDARD 20
		COMPILE_FLAGS "-fno-gnu-unique"
		LIBRARY_OUTPUT_DIRECTORY "../plugins"
		)

add_subdirectory(tests)
add_subdirectory(src)
add_subdirectory(lib)

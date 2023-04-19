cmake_minimum_required(VERSION 3.13)  # CMake version check
set(PROJECT_NAME color)
project(${PROJECT_NAME})               # Create project "arcade"
set(CMAKE_CXX_STANDARD 20)            # Enable c++14 standard
# add compilation flags to access dynamic library
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -fno-gnu-unique -fPIC")

include_directories(../Entity)

set(EXEC_SRC
		Color.cpp
		Api.cpp
		../Entity/Entity.cpp
		)

add_library(${PROJECT_NAME} SHARED ${EXEC_SRC})

target_include_directories(raytracer PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")

set_target_properties(${PROJECT_NAME} PROPERTIES LIBRARY_OUTPUT_DIRECTORY ../../plugins PREFIX "")

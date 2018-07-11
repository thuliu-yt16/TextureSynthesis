cmake_minimum_required(VERSION 2.6)
project(TextureSynthesis)

include_directories(.)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-std=c++11 -O2 -pipe ${CMAKE_CXX_FLAGS}")
set(SOURCE_FILES
	api.cpp
	image.cpp
	main.cpp
	vector3.cpp
    vector2.cpp
)
add_executable(TextureSynthesis ${SOURCE_FILES})

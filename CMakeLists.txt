cmake_minimum_required(VERSION 2.8)
project(CVcli)

set(CMAKE)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_BUILD_TYPE Debug)

file(GLOB CVcli_SOURCES 
		src/*.cpp)

find_package(OpenCV REQUIRED)

include_directories( ${OpenCV_INCLUDE_DIRS} )
include_directories( include/ )

add_executable(CVcli src/main.cpp)
target_link_libraries(CVcli ${OpenCV_LIBS})

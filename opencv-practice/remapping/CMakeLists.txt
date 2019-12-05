cmake_minimum_required(VERSION 3.15)
project(remapping)
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

set(CMAKE_CXX_STANDARD 14)

add_executable(remapping main.cpp)
target_link_libraries( remapping ${OpenCV_LIBS} )